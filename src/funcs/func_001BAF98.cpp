struct Arr_001BAF98 {
    int m_pad[3];
    int m_count;
};

extern "C" int func_001E8248(void* params, unsigned int name, Arr_001BAF98** out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" unsigned int func_001E9300(Arr_001BAF98* a, int i);
extern "C" int func_001E53A0(unsigned int name, int flags);

struct C_001BAF98 {
    int m_pad[12];
    int m30;
    int Call(unsigned int name, void* params);
};

int C_001BAF98::Call(unsigned int name, void* params)
{
    if (name == 0x3A717382) {
        Arr_001BAF98* a = 0;
        func_001E8248(params, 0, &a, 0);
        if (a) {
            int i = a->m_count;
            while (--i != -1) {
                if (m30 == func_001E53A0(func_001E9300(a, i), 0)) return 1;
            }
            return 0;
        }
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return m30 == v;
    }
    return 2;
}
