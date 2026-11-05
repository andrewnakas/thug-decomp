extern "C" float func_00341158(float x);
extern "C" float func_00340BE0(float x);
extern "C" float func_0013B570();

struct Cam_00114D48 {
    char pad[0xB0];
    float m_fov;
    float m_hfov;
    void UpdateFov();
};

void Cam_00114D48::UpdateFov()
{
    float half = m_fov * 0.5f;
    float t = func_00341158(half * 0.01745329425f);
    m_hfov = 2.0f * func_00340BE0(t * func_0013B570()) * 57.29577637f;
}
