#ifndef _RENDER_MANAGET_H_
#define _RENDER_MANAGET_H_

namespace Infinity{

    class RenderManager
    {
    public:
        RenderManager();
        ~RenderManager();

        virtual void createRender() const;
    };

}

#endif//_RENDER_MANAGET_H_