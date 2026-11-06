extern "C" void func_00184920(void* p, unsigned int name, float f, int a);

struct Obj_00270060 {
    char pad[0xC];
    void* mC;
    char pad2[0x24 - 0x10];
    int m24;
    int m28;
    int Dispatch(unsigned int name);
};

int Obj_00270060::Dispatch(unsigned int name)
{
    switch (name) {
    case 0x1EB61DCE:
        return m24 != 0;
    case 0x41EB710B:
        if (!m24) {
            m24 = 1;
            func_00184920(mC, 0x8157AB31, 0.0f, 0);
        }
        break;
    case 0xFB9B7C9C:
        if (m24 == 1) {
            m24 = 0;
            func_00184920(mC, 0x3F70881A, 0.0f, 0);
        }
        break;
    case 0x9FAB9D0B:
        return m28 != 0;
    case 0x0A23D710:
        if (!m28) {
            m28 = 1;
            func_00184920(mC, 0x2E8DE921, 0.0f, 0);
        }
        break;
    case 0x71B57DD6:
        if (m28 == 1) {
            m28 = 0;
            func_00184920(mC, 0xFA9ADB1D, 0.0f, 0);
        }
        break;
    default:
        return 2;
    }
    return 1;
}
