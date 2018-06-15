#ifndef _RENDER_STATE_H_
#define _RENDER_STATE_H_

namespace Infinity{

    class RenderState
    {
    public:
        RenderState();
        ~RenderState();

        virtual void setViewport(int x, int y, int width, int height);
        virtual void setBackgroundColor(float r, float g, float b, float a);
    };
}


#endif//_RENDER_STATE_H_