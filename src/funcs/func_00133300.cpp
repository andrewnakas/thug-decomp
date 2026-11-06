class Scene_00133300;
extern "C" void* func_00132FD0(Scene_00133300* s, unsigned int id);
extern "C" unsigned int func_00133370(Scene_00133300* s, void* src, Scene_00133300* dst, int a, int b);

class Scene_00133300 {
public:
    unsigned int Clone(unsigned int id, Scene_00133300* dst, int a, int b);
};

unsigned int Scene_00133300::Clone(unsigned int id, Scene_00133300* dst, int a, int b)
{
    void* src = func_00132FD0(this, id);
    if (src) {
        return func_00133370(this, src, dst, a, b);
    }
    return 0;
}
