using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPB
{
    public partial class Form1 : Form
    {
        #region rectangle style

        private const int WM_NCHITTEST = 0x84;
        private const int HTCLIENT = 0x1;
        private const int HTCAPTION = 0x2;
        private const int HTBOTTOMRIGHT = 17;

        private const int BORDER_WIDTH = 10;
        private const int CORNER_RADIUS = 10;

        [DllImport("Gdi32.dll", EntryPoint = "CreateRoundRectRgn")]
        private static extern IntPtr CreateRoundRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse);

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            using (GraphicsPath path = new GraphicsPath())
            {
                path.AddArc(new Rectangle(0, 0, CORNER_RADIUS * 2, CORNER_RADIUS * 2), 180, 90);
                path.AddArc(new Rectangle(this.Width - CORNER_RADIUS * 2, 0, CORNER_RADIUS * 2, CORNER_RADIUS * 2), 270, 90);
                path.AddArc(new Rectangle(this.Width - CORNER_RADIUS * 2, this.Height - CORNER_RADIUS * 2, CORNER_RADIUS * 2, CORNER_RADIUS * 2), 0, 90);
                path.AddArc(new Rectangle(0, this.Height - CORNER_RADIUS * 2, CORNER_RADIUS * 2, CORNER_RADIUS * 2), 90, 90);
                path.CloseAllFigures();

                this.Region = new Region(path);
            }
        }

        protected override void WndProc(ref Message m)
        {
            base.WndProc(ref m);

            if (m.Msg == WM_NCHITTEST && (int)m.Result == HTCLIENT)
            {
                m.Result = (IntPtr)HTCAPTION;
            }
        }

        private void RoundedForm_Load(object sender, EventArgs e)
        {
            this.Region = System.Drawing.Region.FromHrgn(CreateRoundRectRgn(0, 0, this.Width, this.Height, CORNER_RADIUS, CORNER_RADIUS));
        }

        #endregion rectangle style

        private bool blokovat = false;

        public Form1()
        {
            InitializeComponent();

            this.FormBorderStyle = FormBorderStyle.None;
            this.DoubleBuffered = true;
            this.SetStyle(ControlStyles.ResizeRedraw, true);
            this.BackColor = Color.FromArgb(30, 30, 30);
        }

        #region buttons
        private void startButton_Click(object sender, EventArgs e)
        {
            blokovat = true;
            vypnout();
            upravitStatusbar();
        }

        private void stopButton_Click(object sender, EventArgs e)
        {
            blokovat = false;
            zapnout();
            upravitStatusbar();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        #endregion buttons

        #region functions

        private void upravitStatusbar()
        {
            statusbar.Text = blokovat ? "Zapnuto" : "Vypnuto";
        }
        private void zapnout()
        {
            string prikaz = "netsh advfirewall firewall delete rule name=\"block all outbound traffic\"";

            ProcessStartInfo pInfo = new ProcessStartInfo("cmd.exe", "/c " + prikaz);
            {
                pInfo.CreateNoWindow = true;
                pInfo.UseShellExecute = false;
            }

            using (Process process = Process.Start(pInfo))
            {
                process.WaitForExit();
            }
        }
        private void vypnout()
        {
            string prikaz = "netsh advfirewall firewall add rule name=\"block all outbound traffic\" dir=out action=block";

            ProcessStartInfo pInfo = new ProcessStartInfo("cmd.exe", "/c " + prikaz);
            {
                pInfo.CreateNoWindow = true;
                pInfo.UseShellExecute = false;
            }

            using (Process process = Process.Start(pInfo))
            {
                process.WaitForExit();
            }

            #endregion buttons

        }
    }
}