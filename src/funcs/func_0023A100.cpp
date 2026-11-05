struct Obj_0023A100 {
    char pad[0x58];
    int m_58;
    int CountPending();
};

extern "C" bool func_0023AC08(Obj_0023A100* self, int index);

int Obj_0023A100::CountPending()
{
    int count = 0;
    for (int i = 0; i < m_58; i++) {
        if (!func_0023AC08(this, i)) {
            count++;
        }
    }
    return count;
}
