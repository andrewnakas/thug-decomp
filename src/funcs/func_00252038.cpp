extern "C" float func_00251DC8(void* self, int idx);

struct Obj_00252038 {
    bool IsTop3(int idx);
};

bool Obj_00252038::IsTop3(int idx)
{
    int order[5];
    for (int i = 4; i >= 0; i--)
        order[i] = i;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 5; j++) {
            if (func_00251DC8(this, order[i]) < func_00251DC8(this, order[j])) {
                int t = order[i];
                order[i] = order[j];
                order[j] = t;
            }
        }
    }
    if (order[0] == idx || order[1] == idx || order[2] == idx)
        return true;
    return false;
}
