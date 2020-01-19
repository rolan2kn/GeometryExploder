
#include <glad/glad.h>


#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "model.h"

#include "ogl_shader_API/util.hpp"

#include <iostream>

#include "ogl_shader_API/shader_program_controller.h"
#include "model_settings_controller.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1280;

// camera
//Camera camera;
Camera camera(glm::vec3(0.0f, 0.0f, 5.0f));
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int option = 0;

ModelSettingsController* modelSettings;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Explode Geometry", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------
    ShaderProgramController* shaderController = new ShaderProgramController();

    string path = directorio_actual() + "/shader_files/";

    shaderController->addShaderFromFile(path+"vertex_shader1.vsh");
    shaderController->addShaderFromFile(path+"geometry_shader1.gsh");
    shaderController->addShaderFromFile(path+"fragment_shader1.fsh");
    shaderController->configure();

    // load models
//    // -----------
//    NANOSUIT, FLY, MALEBODY, AEGYPTOPITHECUS, CATMAC, EYE, SKULL, TRICERATOPS, Z3OBJ

    modelSettings = new ModelSettingsController(NANOSUIT, shaderController);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // configure transformation matrices
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 1.0f, 1000.0f);
        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 model = glm::mat4(modelSettings->getScaleFactor());
        shaderController->configure();

        shaderController->setMat4("projection", projection);
        shaderController->setMat4("view", view);
        shaderController->setMat4("model", model);

        // add time component to geometry shader in the form of a uniform
        shaderController->setFloat("time", glfwGetTime());
        shaderController->setInt("option", option);

        // draw model
        modelSettings->getModel()->Draw();
        string title("Explode Geometry:: Modelo: "+modelSettings->getModelShortFileName() + " Animacion: " + std::to_string(option));
        glfwSetWindowTitle(window, title.c_str());

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        camera = Camera(glm::vec3(0.0f, 0.0f, 5.0f));
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(_SPEED_UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        camera.ProcessKeyboard(_SPEED_DOWN, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
        camera.ProcessKeyboard(TOP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        camera.ProcessKeyboard(BOTTOM, deltaTime);


/**
 *
        NANOSUIT, FLY, MALEBODY, CATMAC,
                EYE, SKULL, TRICERATOPS, Z3OBJ
 * */
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        modelSettings->setModel(NANOSUIT);
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        modelSettings->setModel(FLY);
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        modelSettings->setModel( MALEBODY);
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        modelSettings->setModel(CATMAC);
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
        modelSettings->setModel(EYE);
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
        modelSettings->setModel(SKULL);
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
        modelSettings->setModel(TRICERATOPS);
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
        modelSettings->setModel(Z3OBJ);

    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        option++;
        if (option > 2)
            option = 0;
    }

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}


