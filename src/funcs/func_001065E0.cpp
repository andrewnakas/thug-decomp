extern "C" int func_00336228(const char*, const char*);

bool func_001065E0(const char* name, int argc, char** argv)
{
    if (!name)
        return false;
    for (int i = 0; i < argc; i++) {
        if (func_00336228(argv[i], name) == 0)
            return true;
    }
    return false;
}
