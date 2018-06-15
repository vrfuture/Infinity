#ifndef _RENDER_H_
#define _RENDER_H_

namespace Infinity{
    
    class RenderState;

    class Render
    {
    public:
        Render();
        ~Render();

        void renderWorld();

        inline RenderState *getRenderState() { return m_renderState; }

    private:
        RenderState *m_renderState;     // render state
    };
}

#endif//_RENDER_H_