class Comp_0011FB18;
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" int func_0011FAB8(Comp_0011FB18* self, void* s, int arg);

class Comp_0011FB18 {
public:
    int Run(unsigned int name, int arg);
};

int Comp_0011FB18::Run(unsigned int name, int arg)
{
    return func_0011FAB8(this, func_001E5548(name, 1), arg);
}
