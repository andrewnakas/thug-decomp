extern unsigned int D_0038BDBC;
extern unsigned int D_00393F5C;
extern unsigned int D_00393F58;
extern char D_00371C08[];
extern char D_00371C20[];
extern "C" int func_00103F28(char* fmt, ...);

bool Cmd_00223C28(void* params, void* script)
{
    func_00103F28(D_00371C08, D_0038BDBC >> 2);
    func_00103F28(D_00371C20, (D_00393F5C - D_00393F58) >> 2);
    return true;
}
