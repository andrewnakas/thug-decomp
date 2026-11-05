extern "C" int func_001E7C80(void* params, int name, char** out, int req);
extern "C" int func_0010D970(char* name);

int Cmd_0010DFC8(void* params)
{
    char* name;
    func_001E7C80(params, 0, &name, 1);
    return func_0010D970(name);
}
