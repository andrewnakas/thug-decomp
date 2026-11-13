/* force: {"kind": "ga", "before": [117, 140]} */
/* blocked: global-alloc priority difference (size 29/138 vs loop counter 9/11; forced = MATCH) (oracle) */
struct Array_001EA3B0 {
    char m_pad[0x8];
    int m_type;
    unsigned int m_size;
};

extern "C" char* func_001E91C0(Array_001EA3B0* a, unsigned int i);
extern "C" char* func_001E9218(Array_001EA3B0* a, unsigned int i);
extern "C" unsigned int func_00331BB8(char* s);
extern "C" void* func_001E9378(Array_001EA3B0* a, unsigned int i);
extern "C" int func_001E9CF8(void* s, int max);
extern "C" Array_001EA3B0* func_001E93A0(Array_001EA3B0* a, unsigned int i);

extern "C" int func_001EA3B0(Array_001EA3B0* a)
{
    int size = 3;
    unsigned int n = a->m_size;
    switch (a->m_type) {
    case 0:
        break;
    case 1:
    case 2:
    case 13:
        size = n * 4 + 3;
        break;
    case 3:
        for (unsigned int i = 0; i < n; i++) {
            size++;
            size += func_00331BB8(func_001E91C0(a, i));
        }
        break;
    case 4:
        for (unsigned int i = 0; i < n; i++) {
            size++;
            size += func_00331BB8(func_001E9218(a, i));
        }
        break;
    case 5:
        size = n * 8 + 3;
        break;
    case 6:
        size = n * 12 + 3;
        break;
    case 10:
        for (unsigned int i = 0; i < n; i++) {
            size += func_001E9CF8(func_001E9378(a, i), 100000);
        }
        break;
    case 12:
        for (unsigned int i = 0; i < n; i++) {
            size += func_001EA3B0(func_001E93A0(a, i));
        }
        break;
    }
    return size;
}
