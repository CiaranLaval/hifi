//
//  Skybox.h
//  libraries/model/src/model
//
//  Created by Sam Gateau on 5/4/2015.
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#ifndef hifi_model_Skybox_h
#define hifi_model_Skybox_h

#include "gpu/Texture.h"

#include "Light.h"

class ViewFrustum;
//class Transform;
namespace gpu { class Batch; }

namespace model {

typedef glm::vec3 Color;

class Skybox {
public:
    Skybox();
    Skybox& operator= (const Skybox& skybox);
    virtual ~Skybox() {};
 
    void setColor(const Color& color);
    const Color& getColor() const { return _color; }

    void setCubemap(const gpu::TexturePointer& cubemap);
    const gpu::TexturePointer& getCubemap() const { return _cubemap; }

    static void render(gpu::Batch& batch, const ViewFrustum& frustum, const Skybox& skybox);

protected:
    gpu::TexturePointer _cubemap;

    Color _color{1.0f, 1.0f, 1.0f};
};
typedef std::shared_ptr< Skybox > SkyboxPointer;

};

#endif //hifi_model_Skybox_h
