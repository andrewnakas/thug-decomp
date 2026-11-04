struct RGBA_0020F278 {
    unsigned char r, g, b, a;
};

struct Mesh_0020F278 {
    int m_0;
    int m_4;
    int m_id;
};

extern "C" void func_00132A80(void* table);
extern "C" Mesh_0020F278* func_00132A90(void* table, int* key);
extern "C" void func_00134F28(Mesh_0020F278* m, RGBA_0020F278* c);

struct Scene_0020F278 {
    char pad[0xD0];
    void* m_meshes;

    void SetColor(RGBA_0020F278* color, int id);
};

void Scene_0020F278::SetColor(RGBA_0020F278* color, int id)
{
    void* t = m_meshes;
    if (!t) {
        return;
    }
    func_00132A80(t);
    Mesh_0020F278* m = func_00132A90(t, 0);
    if (id) {
        while (m) {
            if (m->m_id == id) {
                RGBA_0020F278 c = *color;
                func_00134F28(m, &c);
            }
            m = func_00132A90(t, 0);
        }
    } else {
        while (m) {
            RGBA_0020F278 c = *color;
            func_00134F28(m, &c);
            m = func_00132A90(t, 0);
        }
    }
}
