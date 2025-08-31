using System.Diagnostics;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL4;
using OpenTK.Input;
using System;
using System.Collections.Generic;
using System.Drawing;

namespace Avril_FSD_ServerAssembly
{
    public sealed class Game_Instance : GameWindow
    {
        bool done_once;

        readonly string _title;
        double _time;
        readonly Color4 _backColor = new Color4(0.1f, 0.1f, 0.3f, 1.0f);
        FirstPersonCamera _cameraFP;
        ThirdPersonCamera _cameraTP;
        Matrix4 _projectionMatrix;
        float _fov = 45f;

        KeyboardState _lastKeyboardState;
        MouseState _lastMouseState;

        GameObjectFactory _gameObjectFactory;
        readonly List<AGameObject> _gameObjects = new List<AGameObject>();
        
        
        ShaderProgram _texturedProgram;
        ShaderProgram _solidProgram;
        
        bool cameraSelector = false;
       
        public Game_Instance()
            : base(1920, // initial width
                1080, // initial height
                GraphicsMode.Default,
                "",  // initial title
                GameWindowFlags.Fullscreen,
                DisplayDevice.Default,
                4, // OpenGL major version
                5, // OpenGL minor version
                GraphicsContextFlags.ForwardCompatible)
        {
            _title += "dreamstatecoding.blogspot.com: OpenGL Version: " + GL.GetString(StringName.Version);
        }

        protected override void OnResize(EventArgs e)
        {
            GL.Viewport(0, 0, Width, Height);
            CreateProjection();
        }

        protected override void OnLoad(EventArgs e)
        {
            Debug.WriteLine("OnLoad");
            VSync = VSyncMode.Off;
            CreateProjection();
            _solidProgram = new ShaderProgram();
            _solidProgram.AddShader(ShaderType.VertexShader, "..\\..\\..\\..\\graphics\\Shaders\\1Vert\\simplePipeVert.c");
            _solidProgram.AddShader(ShaderType.FragmentShader, "..\\..\\..\\..\\graphics\\Shaders\\5Frag\\simplePipeFrag.c");
            _solidProgram.Link();

            _texturedProgram = new ShaderProgram();
            _texturedProgram.AddShader(ShaderType.VertexShader, "..\\..\\..\\..\\graphics\\Shaders\\1Vert\\simplePipeTexVert.c");
            _texturedProgram.AddShader(ShaderType.FragmentShader, "..\\..\\..\\..\\graphics\\Shaders\\5Frag\\simplePipeTexFrag.c");
            _texturedProgram.Link();

            var models = new Dictionary<string, ARenderable>();
            models.Add("Player", new MipMapGeneratedRenderObject(RenderObjectFactory.CreateTexturedCube6(1, 1, 1), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\gameover.png", 8));
            models.Add("Wooden", new MipMapGeneratedRenderObject(new IcoSphereFactory().Create(3), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\wooden.png", 8));
            models.Add("Golden", new MipMapGeneratedRenderObject(new IcoSphereFactory().Create(3), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\golden.bmp", 8));
            models.Add("Asteroid", new MipMapGeneratedRenderObject(new IcoSphereFactory().Create(3), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\moonmap1k.jpg", 8));
            models.Add("Spacecraft", new MipMapGeneratedRenderObject(RenderObjectFactory.CreateTexturedCube6(1, 1, 1), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\spacecraft.png", 8));
            models.Add("Gameover", new MipMapGeneratedRenderObject(RenderObjectFactory.CreateTexturedCube6(1, 1, 1), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\gameover.png", 8));
            models.Add("Bullet", new MipMapGeneratedRenderObject(new IcoSphereFactory().Create(3), _texturedProgram.Id, "..\\..\\..\\..\\graphics\\Textures\\dotted.png", 8));

            //models.Add("TestObject", new TexturedRenderObject(RenderObjectFactory.CreateTexturedCube(1, 1, 1), _texturedProgram.Id, "..\\..\\..\\graphics\Textures\asteroid texture one side.jpg"));
            //models.Add("TestObjectGen", new MipMapGeneratedRenderObject(RenderObjectFactory.CreateTexturedCube(1, 1, 1), _texturedProgram.Id, "..\\..\\..\\graphics\Textures\asteroid texture one side.jpg", 8));
            //models.Add("TestObjectPreGen", new MipMapManualRenderObject(RenderObjectFactory.CreateTexturedCube(1, 1, 1), _texturedProgram.Id, "..\\..\\..\\graphics\Textures\asteroid texture one side mipmap levels 0 to 8.bmp", 9));

            _gameObjectFactory = new GameObjectFactory(models);

            _gameObjectFactory.Create_PlayerOnClient();
            _gameObjects.Add(_gameObjectFactory.Get_player());

            _gameObjects.Add(_gameObjectFactory.CreateSphericalAsteroid("Wooden", new Vector3(10f, 0f, 0f), new Vector3(1f)));
            _gameObjects.Add(_gameObjectFactory.CreateSphericalAsteroid("Wooden", new Vector3(-10f, 0f, 0f), new Vector3(1f)));
            _gameObjects.Add(_gameObjectFactory.CreateSphericalAsteroid("Golden", new Vector3(0f, 10f, 0f), new Vector3(1f)));
            _gameObjects.Add(_gameObjectFactory.CreateSphericalAsteroid("Golden", new Vector3(0f, -10f, 0f), new Vector3(1f)));
            _gameObjects.Add(_gameObjectFactory.CreateSphericalAsteroid("Asteroid", new Vector3(0f, 0f, 10f), new Vector3(1f)));
            _gameObjects.Add(_gameObjectFactory.CreateSphericalAsteroid("Asteroid", new Vector3(0f, 0f, -10f), new Vector3(1f)));

            //_camera = new StaticCamera();

            _gameObjectFactory.Get_player().Create_Cameras();

            CursorVisible = false;

            GL.PolygonMode(MaterialFace.FrontAndBack, PolygonMode.Fill);
            GL.PatchParameter(PatchParameterInt.PatchVertices, 3);
            GL.PointSize(3);
            GL.Enable(EnableCap.DepthTest);
            GL.Enable(EnableCap.CullFace);
            Closed += OnClosed;
            Debug.WriteLine("OnLoad .. done");
        }

        private void OnClosed(object sender, EventArgs eventArgs)
        {
            Exit();
        }

        public override void Exit()
        {
            Debug.WriteLine("Exit called");
            _gameObjectFactory.Dispose();
            _solidProgram.Dispose();
            _texturedProgram.Dispose();
            base.Exit();
        }

        private void CreateProjection()
        {

            var aspectRatio = (float)Width / Height;
            _projectionMatrix = Matrix4.CreatePerspectiveFieldOfView(
                _fov * ((float)Math.PI / 180f), // field of view angle, in radians
                aspectRatio,                // current window aspect ratio
                0.1f,                       // near plane
                4000f);                     // far plane
        }

        protected override void OnUpdateFrame(FrameEventArgs e)
        {
            _time += e.Time;
            foreach (var item in _gameObjects)
            {
                item.Update(_time, e.Time);
            }
            HandleKeyboard(e.Time);
            HandleMouse();
            switch (cameraSelector)
            {
                case false:
                    Get_gameObjectFactory().Get_player().Get_CameraFP().Update(_time, e.Time);
                    break;

                case true:
                    Get_gameObjectFactory().Get_player().Get_CameraTP().Update(_time, e.Time);
                    break;
            }
        }
        private void HandleMouse()
        {
            Console.WriteLine("TESTBENCH => HandleMouse");
            MouseState mouseState = Mouse.GetCursorState();
            
            if (Framework.GetGameServer().GetData().Get_data_Control().GetFlag_IsPraiseEvent(1) == false)
            {
                if (_gameObjectFactory.Get_player().Get_IsFirstMouseMove()) // This bool variable is initially set to true.
                {
                    _gameObjectFactory.Get_player().Set_MousePos(new Vector2(mouseState.X, mouseState.Y));
                    _gameObjectFactory.Get_player().Set_IsFirstMouseMove(false);
                }
                else
                {
/*
                    switch (cameraSelector)
                    {
                    case false:
                            if ((mouseState.X != (float)(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_X() / 2))
                                || (mouseState.Y != (float)(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_Y() / 2)))
                            {
                                System.Console.WriteLine("TESTBENCH => mouse X = " + mouseState.X + "  mouse Y = " + mouseState.Y);

                                float sensitivity = _gameObjectFactory.Get_player().Get_sensitivity();
                                float anglePerPixle = Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_fov() / Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_Y();
                                float deltaX = anglePerPixle * (mouseState.X - (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_X() / 2));
                                float deltaY = anglePerPixle * (mouseState.Y - (Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_Y() / 2));
                                System.Console.WriteLine("TESTBENCH => deltaX = " + deltaX + "  deltaY = " + deltaY);

                                _gameObjectFactory.Get_player().Get_CameraFP().Update_Yaw(deltaX);
                                System.Console.WriteLine("yaw => " + _gameObjectFactory.Get_player().Get_CameraFP().Get_Yaw());
                                _gameObjectFactory.Get_player().Get_CameraFP().Update_Pitch(deltaY);
                                System.Console.WriteLine("pitch => " + _gameObjectFactory.Get_player().Get_CameraFP().Get_Pitch());

                                Get_gameObjectFactory().Get_player().Get_CameraFP().UpdateVectors();

                                OpenTK.Input.Mouse.SetPosition((double)(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_X() / 2), (double)(Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetSettings().Get_ScreenSize_Y() / 2));

                                
                                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetData_Control().SetIsPraiseEvent(1, true);
                                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetInput_Instnace().GetBuffer_Back_InputDouble().GetInputControl().SelectSetIntputSubset(1);
                                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetInput_Instnace().GetBuffer_Front_InputDouble().SetPraiseEventId(1);
                                    Avril_FSD_ServerAssembly.Praise1_Input input_subset_Praise1 = (Avril_FSD_ServerAssembly.Praise1_Input)Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().GetInput_Instnace().GetBuffer_Front_InputDouble().Get_InputBufferSubset();
                                    input_subset_Praise1.Set_Mouse_X(new_mouseState.X);
                                    input_subset_Praise1.Set_Mouse_Y(new_mouseState.Y);
                                    Avril_FSD_ServerAssembly.Framework.GetGameServer().GetData().Flip_InBufferToWrite();
                                    //Avril_FSD_ServerAssembly.Networking.CreateAndSendNewMessage(1);//todo
                                

                            }
                        break;

                    case true:
                        
                        break;
                    }
*/
                }

                _lastMouseState = mouseState;
                Console.WriteLine("TESTBENCH => HandleMouse .. Done");
            }
        }
        private void HandleKeyboard(double dt)
        {
            var keyState = Keyboard.GetState();

            if (keyState.IsKeyDown(Key.Escape))
            {
                Exit();
            }
            if (keyState.IsKeyDown(Key.W))
            {
                
            }
            if (keyState.IsKeyDown(Key.S))
            {
                
            }

            if (keyState.IsKeyDown(Key.A))
            {
                
            }
            if (keyState.IsKeyDown(Key.D))
            {
                
            }
            _lastKeyboardState = keyState;
        }
        protected override void OnRenderFrame(FrameEventArgs e)
        {
            Title = $"{_title}: FPS:{1f / e.Time:0000.0}, obj:{_gameObjects.Count}";
            GL.ClearColor(Color.Black);// _backColor);
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

            int lastProgram = -1;
            foreach (var obj in _gameObjects)
            {
                var program = obj.Model.Program;
                if (lastProgram != program)
                    GL.UniformMatrix4(20, false, ref _projectionMatrix);
                lastProgram = obj.Model.Program;
                switch (cameraSelector)
                {
                    case false:
                        obj.Render(Get_gameObjectFactory().Get_player().Get_CameraFP());
                        break;

                    case true:
                        obj.Render(Get_gameObjectFactory().Get_player().Get_CameraTP());
                        break;
                }
                

            }
            SwapBuffers();
        }
        public bool Get_cameraSelector()
        {
            return cameraSelector;
        }
        public GameObjectFactory Get_gameObjectFactory()
        {
            return _gameObjectFactory;
        }

    }
}
