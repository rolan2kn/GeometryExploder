//
// Created by rkindela on 04-10-19.
//

#ifndef GEOMETRYEXPLODER_DATA_SETTINGS_H
#define GEOMETRYEXPLODER_DATA_SETTINGS_H
#include <iostream>
#include "ogl_shader_API/util.hpp"
#include "ogl_shader_API/shader_program_controller.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "model.h"

enum MODEL_NAME_ID {NANOSUIT, FLY, MALEBODY, CATMAC,
                    EYE, SKULL, TRICERATOPS, Z3OBJ};

class ModelSettingsController {
private:
    MODEL_NAME_ID modelId;
    Model* model;
    ShaderProgramController* shaderProgramController;
private:
    void createModel();
public:
    ModelSettingsController(MODEL_NAME_ID modelNameId, ShaderProgramController* shaderProgram);
    ~ModelSettingsController();
    void setModel(MODEL_NAME_ID newModelId);
    Model* getModel() const;
    float getScaleFactor() const;
    string getModelFileName();
    string getModelShortFileName();
};


#endif //GEOMETRYEXPLODER_DATA_SETTINGS_H
