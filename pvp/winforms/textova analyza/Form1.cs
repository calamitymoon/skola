using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace textova_analyza
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        #region Počítání slov, vět a odstavců

        private int zpocitatSlova(string text)
        {
            if (string.IsNullOrWhiteSpace(text)) return 0;
            return text.Split(new char[] { ' ', '\t', '\n' }, StringSplitOptions.RemoveEmptyEntries).Length;
        }

        private int zpocitatVety(string text)
        {
            if (string.IsNullOrWhiteSpace(text)) return 0;
            return Regex.Matches(text, @"[.!?]").Count;
        }

        private int zpocitatOdstavce(string text)
        {
            if (string.IsNullOrWhiteSpace(text)) return 0;
            return text.Split(new string[] { "\r\n", "\r", "\n" }, StringSplitOptions.RemoveEmptyEntries).Count();
        }

        #endregion Počítání slov, vět a odstavců

        #region Načítání souborů a analýza

        // Načíst soubor k analýze
        private void bNacist_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Textové soubory|*.txt|Všechny soubory|*.*";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                tbObsah.Text = File.ReadAllText(openFileDialog.FileName);
            }
        }

        // Spustit analýzu
        private void bSpustit_Click(object sender, EventArgs e)
        {
            string obsah = tbObsah.Text;

            int pocetSlov = zpocitatSlova(obsah);
            int pocetVet = zpocitatVety(obsah);
            int pocetOdstavcu = zpocitatOdstavce(obsah);

            lStatistika.Text = $"Slova: {pocetSlov}, věty: {pocetVet}, odstavce: {pocetOdstavcu}";
        }
        #endregion Načítání souborů a analýza
    }
}
