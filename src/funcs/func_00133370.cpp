class Scene_00133370;
extern "C" void* func_001355A8(void* src, int a, int b, Scene_00133370* s);
extern "C" void func_00132FF8(Scene_00133370* s, void* o);
extern "C" unsigned int func_00134F08(void* o);

class Scene_00133370 {
public:
    unsigned int CloneObj(void* src, Scene_00133370* dst, int a, int b);
};

unsigned int Scene_00133370::CloneObj(void* src, Scene_00133370* dst, int a, int b)
{
    Scene_00133370* s = this;
    if (dst) {
        s = dst;
    }
    void* o = func_001355A8(src, a, b, s);
    if (o) {
        func_00132FF8(s, o);
        return func_00134F08(o);
    }
    return 0;
}
