using OpenTK;

namespace Avril_FSD_ServerAssembly
{
    public interface ICamera
    {
        Matrix4 LookAtMatrix { get; }
        void Update(double time, double delta);
    }
}