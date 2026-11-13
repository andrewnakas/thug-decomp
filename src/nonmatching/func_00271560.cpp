/* fuzzy: 94.4 */
/* blocked: game hoists the constant 1 (m60->m1C == 1 test) into a2 in the bnez delay slot. Tried reordering the cases and an if-chain on a local: no gain. */
/* near miss: 13 lines differ. (1) case 0: gcc threads first m58->m1C!=0 test directly into the 0x40 block (game re-tests); (2) else-branch: game loads const 1 into $a2 in the bnez delay slot and switch index in $a0. */
extern void* D_0038C608;
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void* func_00185578(void* obj, unsigned int name);

struct Inner_00271560 {
    char pad[0x1C];
    int m1C;
    int m20;
    char pad2[0xD0 - 0x24];
    int mD0;
};

struct Holder_00271560 {
    char pad[0x5B0];
    Inner_00271560* m5B0;
};

struct Cfg_00271560 {
    char pad[0x20];
    int m20;
    char pad2[0x180 - 0x24];
    int m180;
};

struct Ctx_00271560 {
    char pad[0x34];
    Cfg_00271560* m34;
};

struct Comp_00271560 {
    char pad[0x120];
    int m120;
};

struct Obj_00271560 {
    char pad[0x54];
    Holder_00271560* m54;
    Inner_00271560* m58;
    Ctx_00271560* m5C;
    Inner_00271560* m60;
    void Run(int* mode, int* mask);
};

void Obj_00271560::Run(int* mode, int* mask)
{
    *mask = 0;
    *mode = 0;
    Cfg_00271560* cfg = m5C->m34;
    if (!cfg->m180) {
        if (!cfg->m20) {
            *mode = 0x200;
            *mask |= 0x2000000;
            switch (m54->m5B0->m1C) {
            case 0:
                if (!m54->m5B0->mD0) {
                    Inner_00271560* in = m58;
                    if (!in->m1C && !in->m20) {
                        *mode |= 1;
                        *mask |= 0x10000;
                    }
                }
                if (m58->m1C || m58->m20) {
                    *mode |= 0x40;
                    *mask |= 0x400000;
                }
                break;
            case 4:
                *mode |= 4;
                *mask |= 0x40000;
                break;
            case 2:
                *mode |= 8;
                *mask |= 0x80000;
                break;
            case 3:
                *mode |= 0x10;
                *mask |= 0x100000;
                break;
            case 5:
                *mode |= 0x20;
                *mask |= 0x200000;
                break;
            case 1:
                *mode |= 2;
                *mask |= 0x20000;
                break;
            }
        } else {
            *mode = 0x400;
            *mask |= 0x4000000;
            switch (m60->m1C) {
            case 0:
                *mode |= 1;
                *mask |= 0x10000;
                break;
            case 1:
                *mode |= 2;
                *mask |= 0x20000;
                break;
            case 2:
                *mode |= 0x80;
                *mask |= 0x800000;
                break;
            case 3:
                *mode |= 0x100;
                *mask |= 0x1000000;
                break;
            }
        }
    } else {
        *mode = 0x800;
        *mask |= 0x8000000;
        Comp_00271560* c = (Comp_00271560*)func_00185578(func_00187B48(D_0038C608, 0x824C6A24), 0xE47F1B79);
        if (c->m120) {
            *mode |= 1;
            *mask |= 0x10000;
        } else {
            *mode |= 2;
            *mask |= 0x20000;
        }
    }
}
