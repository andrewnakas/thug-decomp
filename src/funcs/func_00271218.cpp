struct Script_00271218 {
    char pad0[0xB8];
    int m_node;
};

struct Obj_00271218 {
    char pad0[0xC];
    void* m_object;
    int Dispatch(unsigned int name, void* params, Script_00271218* script);
};

extern "C" void func_002717A0(Obj_00271218* self, void* params, Script_00271218* script);
extern "C" void func_00271C90(Obj_00271218* self, void* params, Script_00271218* script);
extern "C" void func_00271D80(Obj_00271218* self, void* params, Script_00271218* script);
extern "C" void func_00272270(Obj_00271218* self, void* params);
extern "C" void func_00272300(Obj_00271218* self, void* params);
extern "C" int func_00229EB0(int node);
extern "C" void* func_00229F48(int node, int index);
extern "C" void* func_00229DF0(void* link);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" void func_00184BC0(void* obj, unsigned int name, int node, int a, int b, int c);

int Obj_00271218::Dispatch(unsigned int name, void* params, Script_00271218* script)
{
    switch (name) {
    case 0x65B9EC39:
        func_002717A0(this, params, script);
        break;
    case 0xFC4F2009:
        func_00271C90(this, params, script);
        break;
    case 0xE5399FB2:
        func_00271D80(this, params, script);
        break;
    case 0x42F80E5E:
        func_00272270(this, params);
        break;
    case 0x0196772B:
        func_00272300(this, params);
        break;
    case 0x4562E4A6: {
        int node = script->m_node;
        if (node != -1) {
            int n = func_00229EB0(node);
            for (int i = 0; i < n; i++) {
                void* s = func_00229DF0(func_00229F48(node, i));
                unsigned int target = 0;
                if (func_001E8398(s, 0x2CA8A299, &target, 0)) {
                    func_00184BC0(m_object, target, script->m_node, 0, 0, 0);
                    break;
                }
            }
        }
        break;
    }
    default:
        return 2;
    }
    return 1;
}
