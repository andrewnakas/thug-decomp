extern int D_0038C7B0;
extern char D_00375130[];
extern char D_00375148[];
extern char D_00375158[];
extern char D_00375168[];

struct Script_002542B8 {
    char m_pad[0xAC];
    int m_AC;
};

struct Slot_002542B8 {
    int m_mode;
    int m_pad[2];
};

struct Mgr_002542B8 {
    char m_pad[0x54];
    Slot_002542B8 m_slots[1];
    int m_60;
    int m_64;
    char m_pad2[0x168 - 0x68];
    int m_168;
    int m_16C;
    int m_170;
};

struct Device_002542B8 {
    char m_pad[0x10];
    int m_10;
};

struct Ctrl_002542B8 {
    char m_pad[0x1C];
    int m_1C;
    int m_20;
};

struct Task_002542B8 {
    char m_pad[0x1C];
    Ctrl_002542B8* m_ctrl;
    Device_002542B8* m_device;
    int m_index;
    int m_pad28;
    Mgr_002542B8* m_data;
};

struct CStruct_002542B8 {
    int m_data[2];
};

extern "C" void func_00189C30(int h);
extern "C" int func_001E5400(const char* name, int a);
extern "C" Script_002542B8* func_001F0938(const char* name, void* params, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_00254760(Mgr_002542B8* m, int a, int index);
extern "C" int func_00254978(Mgr_002542B8* m, int a, int pass, int index, int b);
extern "C" CStruct_002542B8* func_001E6978(CStruct_002542B8* s);
extern "C" void func_001E7268(CStruct_002542B8* s, const char* name, int value);
extern "C" void func_00189750(int h, int ev, unsigned int a, unsigned int b, CStruct_002542B8* s, int c);
extern "C" void func_001E6AE8(CStruct_002542B8* s, int in_chrg);

void ProcessInput_002542B8(Task_002542B8* task)
{
    int h = D_0038C7B0;
    Mgr_002542B8* m = task->m_data;
    func_00189C30(h);
    for (int pass = 0; ; pass++) {
        int ev = 0;
        if (pass == 0) {
            if (m->m_168) {
                m->m_16C = func_001E5400(D_00375130, 0) != 0;
                if (m->m_16C)
                    m->m_170 = func_001F0938(D_00375148, 0, 0, 0, -1, 0, 0, 0, 0, 0)->m_AC;
                m->m_168 = 0;
            }
            ev = func_00254760(m, task->m_ctrl->m_1C, task->m_index);
        }
        int ev2 = func_00254978(m, task->m_ctrl->m_20, pass, task->m_index, task->m_ctrl->m_1C);
        if (ev2)
            ev = ev2;
        if (ev) {
            if (m->m_slots[task->m_index].m_mode && !m->m_64) {
                CStruct_002542B8 s;
                func_001E6978(&s);
                func_001E7268(&s, D_00375158, task->m_device->m_10);
                if (m->m_slots[task->m_index].m_mode == 1)
                    func_001E7268(&s, D_00375168, 0);
                else
                    func_001E7268(&s, D_00375168, 0);
                func_00189750(h, ev, 0x36B2EE74, 0x36B2EE74, &s, 0);
                func_001E6AE8(&s, 2);
            }
        }
        if (!ev)
            break;
    }
}
