extern "C" void func_00135D60();
extern "C" void func_0013AE28();
extern "C" void func_0013B488(float aspect);
extern "C" void func_0013B498(float fov);
extern "C" void func_0013B4A8(float angle);
extern "C" void func_0013AEC8();
extern "C" void func_0013B330(int mode);
extern "C" char* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001329D8(void* self, int bits);
extern "C" void* func_00144EC0(void* self);
extern "C" void func_00143490();
extern "C" void func_00145D08();
extern "C" float func_001E5370(const char* name, int required);

extern void* D_00388A70;
extern void* D_00389C28;
extern void* D_00389C30;
extern char D_0035D428[];   /* "camera_fov" */

/* engine start-up: initialises the subsystems, the camera aspect/FOV, and allocates two global objects */
extern "C" void func_00131840()
{
    for (int i = 3; i >= 0; i--)
        ;
    func_00135D60();
    func_0013AE28();
    func_0013B488(4.0f / 3.0f);
    func_0013B498(func_001E5370(D_0035D428, 0));
    func_0013B4A8(0.0f);
    func_0013AEC8();
    func_0013B330(0);
    D_00389C28 = func_001329D8(func_0010A638(D_00388A70, 0x18, 1, 0), 6);
    D_00389C30 = func_00144EC0(func_0010A638(D_00388A70, 8, 1, 0));
    func_00143490();
    func_00145D08();
}
