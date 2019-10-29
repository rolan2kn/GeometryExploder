//
// Created by rkindela on 04-10-19.
//

#include "model_settings_controller.h"


ModelSettingsController::ModelSettingsController(MODEL_NAME_ID _modelId, ShaderProgramController* shaderProgram)
:modelId(_modelId), model(nullptr), shaderProgramController(shaderProgram)
{
    this->createModel();
}

ModelSettingsController::~ModelSettingsController()
{
    if(model != nullptr)
        delete model;
}

Model* ModelSettingsController::getModel() const
{
    return model;
}

void ModelSettingsController::createModel()
{
    if(this->model != nullptr)
        delete this->model;

    string filename = this->getModelFileName();
    if (!existe_archivo(filename))
        throw NewException("Se esperaba un modelo válido");

    this->model = new Model(shaderProgramController, filename);
}

void ModelSettingsController::setModel(MODEL_NAME_ID newModelId)
{
    if (this->modelId == newModelId)
        return;
    this->modelId = newModelId;
    this->createModel();
}

float ModelSettingsController::getScaleFactor() const
{
    /*
     * NANOSUIT, FLY, MALEBODY, AEGYPTOPITHECUS, ARNOLD, AUGUSTUS, BUNNY, CATMAC,
                    EYE, HEARTH, JAW, MASK_HEAD, OLD_MAN, REX, SKULL, TREX_SKEL, TRICERATOPS, Z3OBJ, FREE_MALE
     * */
    switch (this->modelId)
    {
        case NANOSUIT:
            return 0.1f;
        case FLY:
            return 0.0001f;
        case MALEBODY:
            return 0.005f;
        case Z3OBJ:
            return 0.002f;
        case TRICERATOPS:
            return 0.005f;
        case SKULL:
            return 0.02f;
        case CATMAC:
        case EYE:
            return 1.0f;
    }
    return 1.0f;
}

string ModelSettingsController::getModelShortFileName()
{
    switch (this->modelId)
    {
        case NANOSUIT:
            return "Nanosuit.obj";
        case FLY:
            return "fly.obj";
        case MALEBODY:
            return "malebody_BETA1.obj";
        case CATMAC:
            return "CatMac.obj";
        case EYE:
            return "Eye.obj";
        case SKULL:
            return "Skull.obj";
        case TRICERATOPS:
            return "Triceratops.obj";
        case Z3OBJ:
            return "Z3_OBJ.obj";
    }
    return "Nanosuit.obj";
}

string ModelSettingsController::getModelFileName()
{
    switch (this->modelId)
    {
        case NANOSUIT:
            return string(directorio_actual() + "/resources/Nano_suit/Nanosuit.obj");
        case FLY:
            return string(directorio_actual() + "/resources/FLY/fly.obj");
        case MALEBODY:
            return string(directorio_actual() + "/resources/malebody/malebody_BETA1.obj");
        case CATMAC:
            return directorio_actual() + "/resources/catmac/CatMac.obj";
        case EYE:
            return directorio_actual() + "/resources/Eye/Eye.obj";
        case SKULL:
            return directorio_actual() + "/resources/Skull/Skull.obj";
        case TRICERATOPS:
            return directorio_actual() + "/resources/Triceratops-skeleton/Triceratops.obj";
        case Z3OBJ:
            return directorio_actual() + "/resources/Z3_OBJ/Z3_OBJ.obj";
    }
    return string(directorio_actual() + "/resources/Nano_suit/Nanosuit.obj");
}