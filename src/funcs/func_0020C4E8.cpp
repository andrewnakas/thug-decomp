typedef int qword_0020C4E8 __attribute__((mode(TI)));

struct Vec_0020C4E8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0020C4E8 q;
    };
};

struct Script_0020C4E8 {
    char m_pad[0x18];
    void* m_params;
};

extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_0020C4E8* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_0029C320();
extern "C" void func_0029ABB8(void* mgr, Vec_0020C4E8* pos, Vec_0020C4E8* out, float* dist, unsigned int* a, int* b, unsigned int name, int id);
extern "C" void** func_002C0368();
extern "C" void func_002B96B0(void* mgr, Vec_0020C4E8* pos, Vec_0020C4E8* out, float* dist);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);

bool ScriptCmd_0020C4E8(void* params, Script_0020C4E8* script)
{
    Vec_0020C4E8 pos;
    Vec_0020C4E8 nodePos;
    Vec_0020C4E8 railPos;
    Vec_0020C4E8 result;
    func_001E7FA8(params, 0x7F261953, &pos, 1);
    float radius = 150.0f;
    func_001E7EB0(params, 0x213395F1, &radius, 0);
    float radiusSq = radius * radius;
    unsigned int name = 0;
    func_001E8398(params, 0x288A6EFE, &name, 0);
    int id = -1;
    func_001E7DE8(params, 0xE4D305A7, &id, 0);
    float nodeDist = 100000000.0f;
    unsigned int node = 0;
    int link = 0;
    func_0029ABB8(func_0029C320(), &pos, &nodePos, &nodeDist, &node, &link, name, id);
    float railDist = 100000000.0f;
    if (func_001E8708(params, 0x9C247A94)) {
        func_002B96B0(*func_002C0368(), &pos, &railPos, &railDist);
    }
    if (nodeDist < radiusSq || railDist < radiusSq) {
        if (nodeDist < railDist) {
            result.q = nodePos.q;
            func_001E7360(script->m_params, 0xA61E7CD9, node);
            func_001E7200(script->m_params, 0x00AB3C14, link);
        } else {
            result.q = railPos.q;
        }
        func_001E7410(script->m_params, 0xDF970A05, result.x, result.y, result.z);
        return true;
    }
    return false;
}
