/* force: {"kind": "sched", "pass": 2, "block": 0, "clock": 3, "first": [65, 5]} */
/* force: {"kind": "sched", "pass": 2, "block": 0, "clock": 9, "first": [27, 29]} */
/* force: {"kind": "sched", "pass": 2, "block": 0, "clock": 10, "first": [35, 25]} */
extern void* D_0038E8A4;
extern "C" void* func_001F2F88(void* mgr, unsigned int id);

struct Script_001EEF18 {
    char pad0[0xBC];
    void* mBC;
    void Run(unsigned int id, void* params);
};

extern "C" void func_001EECE8(Script_001EEF18* self, unsigned int id, void* script, void* params, void* d, int e);
extern "C" void func_001EFDC0(Script_001EEF18* self);

void Script_001EEF18::Run(unsigned int id, void* params)
{
    func_001EECE8(this, id, func_001F2F88(D_0038E8A4, id), params, mBC, 1);
    func_001EFDC0(this);
}
