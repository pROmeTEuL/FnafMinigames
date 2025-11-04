#include "takecaketochildrenuipanel.h"
#include "shadermanager.h"

TakeCakeToChildrenUIPanel::TakeCakeToChildrenUIPanel(Vector2i res)
    : UIPanel(res,
            res.x, // Start 2/10 accross
            res.y, // 1/3 of the resolution from the top
            res.x, // as wide as 6/10 of the resolution
            res.y, // and as tall as 1/3 of the resolution
            0, 0, 0, 0) // a, r, g, b
{

}

void TakeCakeToChildrenUIPanel::draw(RenderWindow &window, Shader *shader)
{
    show();
    UIPanel::draw(window, ShaderManager::instance().getFragment(""));
}

