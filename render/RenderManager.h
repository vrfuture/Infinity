#ifndef _RENDER_MANAGET_H_
#define _RENDER_MANAGET_H_

namespace Infinity{

    class RenderManager
    {
    public:
        RenderManager();
        ~RenderManager();

        virtual void createRender() const;

        // use and unuse shader
        static unsigned int getProgramID();
        static void setProgramID(unsigned int program);

    private:
        static unsigned int s_program_id;
    };

}

#endif//_RENDER_MANAGET_H_