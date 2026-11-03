extern "C" void func_001F9EC0();
extern "C" int func_003267F8();
extern "C" int func_00324540(int, void (*)(), int*);
extern "C" int func_00324700(int, void (*)(), int*);
extern "C" void func_003247E8(int);
extern "C" void func_00326938();

struct Net_001F9018 {
    char m_pad[0x2A8];
    int m2A8;
};

extern "C" void func_001FA6A0(Net_001F9018*, int);

void func_001F9018(Net_001F9018* n)
{
    int x;
    func_003267F8();
    int ok = n->m2A8 && func_00324540(10, func_001F9EC0, &x) == 0;
    if (!ok) {
        int done;
        do {
            done = 1;
            int r = func_00324700(10, func_001F9EC0, &x);
            if (r) {
                done = 0;
                if (r == 3)
                    break;
                func_003247E8(1000);
            }
        } while (!done);
    }
    func_001FA6A0(n, 5);
    n->m2A8 = 0;
    func_00326938();
}
