extern char D_0035CE70[];
extern "C" int func_001E87B8(void* params, const char* name);

class Elem_0012AB50;
extern "C" void func_00124868(Elem_0012AB50* self, void* params);
extern "C" void func_00129508(Elem_0012AB50* self);

class Elem_0012AB50 {
public:
    int m0;
    void SetProps(void* params);
};

void Elem_0012AB50::SetProps(void* params)
{
    func_00124868(this, params);
    if (func_001E87B8(params, D_0035CE70)) {
        func_00129508(this);
    }
}
