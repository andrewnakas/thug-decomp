extern "C" int func_0023C040(void* self);
extern "C" void* func_00243C18(void* list, int* idx, int* out);
extern "C" int func_00245580(void* item, void* arg);

int func_0023D0A8(char* self, void* arg)
{
    int result = 0;
    int i = 0;
    int tmp;
    for (; i < func_0023C040(self); i++) {
        result = func_00245580(func_00243C18(self + 4, &i, &tmp), arg);
    }
    return result;
}
