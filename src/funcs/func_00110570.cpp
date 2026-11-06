struct Port_00110570 {
    int m_handle;
};

extern int D_00388E20;
extern "C" int func_0031EB08(int h);
extern "C" void func_0010FD30(Port_00110570* p);

extern "C" int func_00110570(Port_00110570* p)
{
    if (p) {
        if (!D_00388E20) {
            return -1;
        }
        func_0031EB08(p->m_handle);
        func_0010FD30(p);
        D_00388E20--;
        return 0;
    }
    return -1;
}
