namespace textova_analyza
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.bNacist = new System.Windows.Forms.Button();
            this.tbObsah = new System.Windows.Forms.TextBox();
            this.bSpustit = new System.Windows.Forms.Button();
            this.lStatistika = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // bNacist
            // 
            this.bNacist.Location = new System.Drawing.Point(385, 12);
            this.bNacist.Name = "bNacist";
            this.bNacist.Size = new System.Drawing.Size(100, 23);
            this.bNacist.TabIndex = 0;
            this.bNacist.Text = "Načíst soubor";
            this.bNacist.UseVisualStyleBackColor = true;
            this.bNacist.Click += new System.EventHandler(this.bNacist_Click);
            // 
            // tbObsah
            // 
            this.tbObsah.Location = new System.Drawing.Point(12, 28);
            this.tbObsah.Multiline = true;
            this.tbObsah.Name = "tbObsah";
            this.tbObsah.ReadOnly = true;
            this.tbObsah.Size = new System.Drawing.Size(367, 504);
            this.tbObsah.TabIndex = 2;
            this.tbObsah.Text = "[ zobrazení obsah souboru ]";
            this.tbObsah.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // bSpustit
            // 
            this.bSpustit.Location = new System.Drawing.Point(410, 41);
            this.bSpustit.Name = "bSpustit";
            this.bSpustit.Size = new System.Drawing.Size(75, 23);
            this.bSpustit.TabIndex = 1;
            this.bSpustit.Text = "Analyzovat";
            this.bSpustit.UseVisualStyleBackColor = true;
            this.bSpustit.Click += new System.EventHandler(this.bSpustit_Click);
            // 
            // lStatistika
            // 
            this.lStatistika.AutoSize = true;
            this.lStatistika.Location = new System.Drawing.Point(12, 12);
            this.lStatistika.Name = "lStatistika";
            this.lStatistika.Size = new System.Drawing.Size(139, 13);
            this.lStatistika.TabIndex = 3;
            this.lStatistika.Text = "[ počet slov, vět, odstavců ]";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(497, 544);
            this.Controls.Add(this.lStatistika);
            this.Controls.Add(this.bSpustit);
            this.Controls.Add(this.tbObsah);
            this.Controls.Add(this.bNacist);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Analýza textu";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bNacist;
        private System.Windows.Forms.TextBox tbObsah;
        private System.Windows.Forms.Button bSpustit;
        private System.Windows.Forms.Label lStatistika;
    }
}

