struct File_00110980;
extern "C" int func_001092D0();
extern "C" int func_00109598(File_00110980* f);
extern "C" int func_001092E0();

struct File_00110980 {
    int m0;
    int m4;
    int m_size;
    int GetSize();
};

int File_00110980::GetSize()
{
    if (func_001092D0()) {
        int n = func_00109598(this);
        if (func_001092E0()) {
            return n;
        }
    }
    return m_size;
}
