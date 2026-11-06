extern int D_0038881C;
extern int D_0038880C;
extern int D_0038882C;
extern int D_00392A84;
extern char D_100B280[];
extern char D_0037B018[];
extern char D_0037B028[];
extern char D_00392A88[];
extern "C" void func_00106838();
/* the size operand is a code label inside func_00106838: (char*)func_00106838 + 0x81 = .L001068B8 + 1 */

extern "C" void* func_00110E38(char* name, char* mode);
extern "C" int func_00111038(char* buf, int a, int size, void* f);
extern "C" int func_00111190(void* f);
extern "C" int func_00110EF8(void* f);

extern "C" int func_002CF338()
{
    if (D_0038881C)
        D_00392A84 = 1;
    if (!D_00392A84) {
        void* f;
        if (D_0038880C == 2 && D_0038882C == 1)
            f = func_00110E38(D_0037B018, D_00392A88);
        else
            f = func_00110E38(D_0037B028, D_00392A88);
        func_00111038(D_100B280, 1, (int)((char*)func_00106838 + 0x81), f);
        func_00111190(f);
        func_00110EF8(f);
        D_00392A84 = 1;
    }
    return 1;
}
