extern unsigned char D_00393F10;
extern unsigned char D_00393F11;
extern unsigned char D_00393F12;
extern unsigned char D_00393F13;

extern "C" void func_00144BA0(void* p, int id)
{
    if (id == 0xFFFF && p) {
        D_00393F10 = 0x60;
        D_00393F11 = 0x60;
        D_00393F12 = 0x80;
        D_00393F13 = 0x66;
    }
}
