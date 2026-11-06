extern "C" bool func_0014F148(void* self, void* a, void* b, void* c);

bool func_0014F270(void* self, void* a, void* b, void* c)
{
    if (func_0014F148(self, a, b, c) && func_0014F148(self, b, a, c) && func_0014F148(self, c, a, b))
        return true;
    return false;
}
