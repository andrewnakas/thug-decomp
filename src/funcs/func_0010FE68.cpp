extern int D_0038881C;
extern int D_00388E1C;
extern char D_0035BBF8[];
extern "C" void func_00103F28(const char* msg);
extern "C" int func_00329400();

extern "C" void func_0010FE68()
{
    if (D_0038881C) {
        if (D_00388E1C) {
            while (!func_00329400()) {
                func_00103F28(D_0035BBF8);
            }
        }
        D_00388E1C = 0;
    }
}
