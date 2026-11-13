/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 1, "first": [68, 51]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 2, "first": [181, 47]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 3, "first": [182, 72]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 4, "first": [74, 96]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 9, "first": [183, 85]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 10, "first": [184, 89]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 13, "first": [185, 102]} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 14, "first": [186, 106]} */
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" void* func_00139468(void* node, unsigned int id);
extern "C" void func_001388C8(void* c, bool b, float x, float y, float z);
extern void* D_00393EF4;

bool Cmd_0013A5B0(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0, &id, 0);
    void* c = func_00139468(D_00393EF4, id);
    if (c) {
        float x = 0.0f;
        float y = 1.0f;
        float z = 1.0f;
        int v = 0;
        func_001E7EB0(params, 0x6E94F918, &x, 0);
        func_001E7EB0(params, 0xE4F130F4, &y, 0);
        func_001E7EB0(params, 0x949BC47B, &z, 0);
        func_001E7DE8(params, 0xC164842A, &v, 0);
        func_001388C8(c, v == 1, x, y, z);
    }
    return true;
}
