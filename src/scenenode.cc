#include <utility>
#include <memory>
#include <iostream>

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "scenenode.h"
#include "model.h"
#include "camera.h"

//using namespace std;
namespace Hodhr {

SceneNode::SceneNode (const std::string& name)
{
  this->name = name;
  this->asset = NULL;
}

SceneNode::~SceneNode()
{



}

void SceneNode::draw()
{
    
  //cout << "drawing node " << name << endl;
  if (asset) 
    {
      // cout << "drawing asset in " << name << endl;
      asset->draw(*this);
    }

  

  for (int index=0; index< children.size(); ++index)
    {
      children[index]->draw();
    }
  
}

void SceneNode::setPosition(float x, float y, float z)
{
  this->Position = glm::vec3(x,y,z);
}

void SceneNode::addChild(std::unique_ptr<SceneNode> node)
{
    //auto tnode = unique_ptr<SceneNode>(node);
    children.push_back( move(node) );

}

void SceneNode::setAsset(Model* model)
{
  std::cout << "Setting asset for " << name << std::endl;
    asset = model;
}

glm::mat4 SceneNode::getMVPMatrix() const
{
    return MVPMatrix;
}

void SceneNode::updateLocal(Camera& camera)
{
    //std::cout << "Updating transformation matrix" << std::endl;
  glm::mat4 Model = glm::translate(
				   glm::mat4(1.0f),
				   Position);
    
    MVPMatrix = camera.getProjectionMatrix() * camera.getViewMatrix() * Model;
}

void SceneNode::updateAll(Camera& camera)
{
    updateLocal(camera);
    for (std::vector<std::unique_ptr<SceneNode>>::iterator it = children.begin(); it != children.end(); ++it)
    {
        (*it)->updateAll(camera);
    }
}

}