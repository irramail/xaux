#include <gtk/gtk.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <sys/wait.h>

static int eq1, eq2, eq3, eq4, eq5, eq6, eq7, eq8, eq9, eq0;
static int v1, v2, v3, v4, v5;
static int tv0, tv1, tv2, tv3, tv4, tv5, tv6, tv7, tv8, tv9, tv10, tv11, tv12, tv13, tv14, tv15, tv16, tv17, tv18, tv19, tv20, tv21, tv22, tv23;

const std::string FNMV = "./task/MUSIC_VOL";
const std::string FNJV = "./task/JINGL_VOL";
const std::string FNEQ = "./eq";
const std::string FNVFD = "./task/VOLSOFDAY";

void run_script(const char *arg) {
  pid_t child;
  std::string fname = "/tmp/xmxmp.sh";
  std::ofstream ofile;
  ofile.open(fname.c_str());
  ofile << "#!/bin/sh" << std::endl;
  ofile << "killall -q -9 test" << std::endl;
  ofile << "killall -q -9 mplayer" << std::endl;

  ofile << "amixer -q sset Master unmute" << std::endl;
  ofile << "amixer -q sset Headphone unmute" << std::endl;
  ofile << "amixer -q sset PCM unmute" << std::endl;

  ofile << "amixer -q sset Master " << v1 << "%" << std::endl;
  ofile << "amixer -q sset Headphone " << v1 << "%" << std::endl;
  ofile << "amixer -q sset PCM " << v2 << "%," << v3 << "%" << std::endl;
  ofile << "DISPLAY=:0.0 mplayer -softvol -af equalizer="<< eq1 << ":" << eq2 << ":" << eq3 << ":" << eq4 << ":" << eq5 << ":" << eq6 << ":" << eq7 << ":" << eq8 << ":" << eq9 << ":" << eq0 << " -loop 0 -nolirc -really-quiet " << arg << " &"<< std::endl;
  ofile.close();

  if (!(child = fork())) {
    execlp("/bin/sh", "/bin/sh", fname.c_str(), NULL);
      exit(0);
    }
  wait(0);
}

void Dialog() {
  GtkWidget *dialog;
     
  dialog = gtk_file_chooser_dialog_new ("Open File",
					NULL,
					GTK_FILE_CHOOSER_ACTION_OPEN,
					GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
					GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
					NULL);
     
  if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
     
      filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
      run_script(filename);
      g_free (filename);      
    }
     
  gtk_widget_destroy (dialog);
}

void loadTimeVol() {
  std::ifstream vol;
  std::string tmpStr, mv, jv;

  vol.open(FNVFD.c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv0=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv1=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv2=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv3=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv4=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv5=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv6=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv7=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv8=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv9=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv10=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv11=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv12=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv13=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv14=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv15=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv16=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv17=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv18=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv19=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv20=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv21=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv22=atoi(tmpStr.substr(9).c_str());
  tmpStr.clear();
  if(vol.good())
    std::getline(vol, tmpStr);
  if(tmpStr.length() > 9)
    tv23=atoi(tmpStr.substr(9).c_str());

  vol.close();
}

void loadVolConfig() {
  std::ifstream vol;
  std::string tmpStr, mv, jv;

  vol.open(FNMV.c_str());
  if(vol.good())
    std::getline(vol, tmpStr);
  vol.close();
  mv = tmpStr;

  tmpStr.clear();
  vol.open(FNJV.c_str());
  if(vol.good())
    std::getline(vol, tmpStr);
  vol.close();
  jv = tmpStr;

  if(mv.length() == 0)
    mv = "0:0:0";

  if(jv.length() == 0)
    jv = "0:0:0";

  v1 = atoi(mv.c_str());
  if(mv.find(':') != std::string::npos)
    mv.erase(mv.begin(), mv.begin() + mv.find_first_of(':') + 1);
  v2 = atoi(mv.c_str());
  if(mv.find(':') != std::string::npos)
    mv.erase(mv.begin(), mv.begin() + mv.find_first_of(':') + 1);
  v3 = atoi(mv.c_str());

  if(jv.find(':') != std::string::npos)
    jv.erase(jv.begin(), jv.begin() + jv.find_first_of(':') + 1);
  v4 = atoi(jv.c_str());
  if(jv.find(':') != std::string::npos)
    jv.erase(jv.begin(), jv.begin() + jv.find_first_of(':') + 1);
  v5 = atoi(jv.c_str());
}

void loadEqConfig() {
  std::ifstream eq;
  std::string tmpStr;

  eq.open(FNEQ.c_str());
  if(eq.good())
    std::getline(eq, tmpStr);
  eq.close();

  if(tmpStr.length() == 0)
    tmpStr = "0:0:0:0:0:0:0:0:0:0";

  eq1 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq2 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq3 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq4 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq5 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq6 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq7 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq8 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq9 = atoi(tmpStr.c_str());
  if(tmpStr.find(':') != std::string::npos)
    tmpStr.erase(tmpStr.begin(), tmpStr.begin() + tmpStr.find_first_of(':') + 1);
  eq0 = atoi(tmpStr.c_str());
}

void saveTimeVol() {
  std::ofstream ofile;

  ofile.open(FNVFD.c_str());
  ofile << "00:00:00;" << tv0 << std::endl;
  ofile << "01:00:00;" << tv1 << std::endl;
  ofile << "02:00:00;" << tv2 << std::endl;
  ofile << "03:00:00;" << tv3 << std::endl;
  ofile << "04:00:00;" << tv4 << std::endl;
  ofile << "05:00:00;" << tv5 << std::endl;
  ofile << "06:00:00;" << tv6 << std::endl;
  ofile << "07:00:00;" << tv7 << std::endl;
  ofile << "08:00:00;" << tv8 << std::endl;
  ofile << "09:00:00;" << tv9 << std::endl;
  ofile << "10:00:00;" << tv10 << std::endl;
  ofile << "11:00:00;" << tv11 << std::endl;
  ofile << "12:00:00;" << tv12 << std::endl;
  ofile << "13:00:00;" << tv13 << std::endl;
  ofile << "14:00:00;" << tv14 << std::endl;
  ofile << "15:00:00;" << tv15 << std::endl;
  ofile << "16:00:00;" << tv16 << std::endl;
  ofile << "17:00:00;" << tv17 << std::endl;
  ofile << "18:00:00;" << tv18 << std::endl;
  ofile << "19:00:00;" << tv19 << std::endl;
  ofile << "20:00:00;" << tv20 << std::endl;
  ofile << "21:00:00;" << tv21 << std::endl;
  ofile << "22:00:00;" << tv22 << std::endl;
  ofile << "23:00:00;" << tv23 << std::endl;
  ofile.close();
}

void saveVolConfig() {
  std::ofstream ofile;

  ofile.open(FNMV.c_str());
  ofile << v1 << ":" <<v2 << ":" <<v3 << std::flush;
  ofile.close();

  ofile.open(FNJV.c_str());
  ofile << v1 << ":" <<v4 << ":" <<v5 << std::flush;
  ofile.close();
}

void saveEqConfig() {
  std::ofstream ofile;

  ofile.open(FNEQ.c_str());
  ofile << eq1 << ":" <<eq2 << ":" <<eq3 << ":" <<eq4 << ":" <<eq5 << ":" <<eq6 << ":" <<eq7 << ":" <<eq8 << ":" <<eq9 << ":" <<eq0 << std::flush;
  ofile.close();
}

//------------------------------------------------------------------------------------------------------

static void
spin_clickedTv0 (GtkSpinButton *spinbutton)
{
  tv0 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv1 (GtkSpinButton *spinbutton)
{
  tv1 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv2 (GtkSpinButton *spinbutton)
{
  tv2 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv3 (GtkSpinButton *spinbutton)
{
  tv3 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv4 (GtkSpinButton *spinbutton)
{
  tv4 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv5 (GtkSpinButton *spinbutton)
{
  tv5 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv6 (GtkSpinButton *spinbutton)
{
  tv6 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv7 (GtkSpinButton *spinbutton)
{
  tv7 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv8 (GtkSpinButton *spinbutton)
{
  tv8 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv9 (GtkSpinButton *spinbutton)
{
  tv9 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv10 (GtkSpinButton *spinbutton)
{
  tv10 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv11 (GtkSpinButton *spinbutton)
{
  tv11 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv12 (GtkSpinButton *spinbutton)
{
  tv12 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv13 (GtkSpinButton *spinbutton)
{
  tv13 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv14 (GtkSpinButton *spinbutton)
{
  tv14 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv15 (GtkSpinButton *spinbutton)
{
  tv15 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv16 (GtkSpinButton *spinbutton)
{
  tv16 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv17 (GtkSpinButton *spinbutton)
{
  tv17 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv18 (GtkSpinButton *spinbutton)
{
  tv18 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv19 (GtkSpinButton *spinbutton)
{
  tv19 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv20 (GtkSpinButton *spinbutton)
{
  tv20 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv21 (GtkSpinButton *spinbutton)
{
  tv21 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv22 (GtkSpinButton *spinbutton)
{
  tv22 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}
static void
spin_clickedTv23 (GtkSpinButton *spinbutton)
{
  tv23 = gtk_spin_button_get_value_as_int (spinbutton);
  saveTimeVol();
}

//------------------------------------------------------------------------------------------------------

static void
spin_clickedV1 (GtkSpinButton *spinbutton)
{
  v1 = gtk_spin_button_get_value_as_int (spinbutton);
  saveVolConfig();
}
static void
spin_clickedV2 (GtkSpinButton *spinbutton)
{
  v2 = gtk_spin_button_get_value_as_int (spinbutton);
  saveVolConfig();
}
static void
spin_clickedV3 (GtkSpinButton *spinbutton)
{
  v3 = gtk_spin_button_get_value_as_int (spinbutton);
  saveVolConfig();
}
static void
spin_clickedV4 (GtkSpinButton *spinbutton)
{
  v4 = gtk_spin_button_get_value_as_int (spinbutton);
  saveVolConfig();
}
static void
spin_clickedV5 (GtkSpinButton *spinbutton)
{
  v5 = gtk_spin_button_get_value_as_int (spinbutton);
  saveVolConfig();
}

static void
spin_clicked1 (GtkSpinButton *spinbutton)
{
  eq1 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked2 (GtkSpinButton *spinbutton)
{
  eq2 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked3 (GtkSpinButton *spinbutton)
{
  eq3 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked4 (GtkSpinButton *spinbutton)
{
  eq4 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked5 (GtkSpinButton *spinbutton)
{
  eq5 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked6 (GtkSpinButton *spinbutton)
{
  eq6 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked7 (GtkSpinButton *spinbutton)
{
  eq7 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked8 (GtkSpinButton *spinbutton)
{
  eq8 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked9 (GtkSpinButton *spinbutton)
{
  eq9 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}
static void
spin_clicked0 (GtkSpinButton *spinbutton)
{
  eq0 = gtk_spin_button_get_value_as_int (spinbutton);
  saveEqConfig();
}

void
destroy (void)
{
  gtk_main_quit ();
}

int main( int argc, char *argv[])
{
  loadTimeVol();
  loadEqConfig();
  loadVolConfig();

  GtkWidget *window;
  GtkAdjustment *spinner_adj1, *spinner_adj2, *spinner_adj3, *spinner_adj4, *spinner_adj5, *spinner_adj11, *spinner_adj12, *spinner_adj13, *spinner_adj14, *spinner_adj15, *spinner_adj16, *spinner_adj17, *spinner_adj18, *spinner_adj19, *spinner_adj10;

  GtkAdjustment *spinner_avd0, *spinner_avd1, *spinner_avd2, *spinner_avd3, *spinner_avd4, *spinner_avd5, *spinner_avd6, *spinner_avd7, *spinner_avd8, *spinner_avd9, *spinner_avd10, *spinner_avd11, *spinner_avd12, *spinner_avd13, *spinner_avd14, *spinner_avd15, *spinner_avd16, *spinner_avd17, *spinner_avd18, *spinner_avd19, *spinner_avd20, *spinner_avd21, *spinner_avd22, *spinner_avd23;

  GtkWidget *fixed;

  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *spinner1, *spinner2, *spinner3, *spinner4, *spinner5, *spinner11, *spinner12, *spinner13, *spinner14, *spinner15, *spinner16, *spinner17, *spinner18, *spinner19, *spinner10;

  GtkWidget *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9, *l10, *l11, *l12, *l13, *l14, *l15, *l16, *l17, *l18, *l19, *l20, *l21, *l22, *l23;

  GtkWidget *spinner_vd0, *spinner_vd1, *spinner_vd2, *spinner_vd3, *spinner_vd4, *spinner_vd5, *spinner_vd6, *spinner_vd7, *spinner_vd8, *spinner_vd9, *spinner_vd10, *spinner_vd11, *spinner_vd12, *spinner_vd13, *spinner_vd14, *spinner_vd15, *spinner_vd16, *spinner_vd17, *spinner_vd18, *spinner_vd19, *spinner_vd20, *spinner_vd21, *spinner_vd22, *spinner_vd23;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "GtkFixed");
  gtk_window_set_default_size(GTK_WINDOW(window), 565, 130);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);

  button1 = gtk_button_new_with_label("Play");
  gtk_fixed_put(GTK_FIXED(fixed), button1, 395, 15 );
  gtk_widget_set_size_request(button1, 80, 25);

  button2 = gtk_button_new_with_label("Exit");
  gtk_fixed_put(GTK_FIXED(fixed), button2, 480, 15);
  gtk_widget_set_size_request(button2, 80, 25);

  spinner_adj1 = (GtkAdjustment *) gtk_adjustment_new (v1, 0.0, 100.0, 1.0, 0, 0);
  spinner_adj2 = (GtkAdjustment *) gtk_adjustment_new (v2, 0.0, 100.0, 1.0, 0, 0);
  spinner_adj3 = (GtkAdjustment *) gtk_adjustment_new (v3, 0.0, 100.0, 1.0, 0, 0);
  spinner_adj4 = (GtkAdjustment *) gtk_adjustment_new (v4, 0.0, 100.0, 1.0, 0, 0);
  spinner_adj5 = (GtkAdjustment *) gtk_adjustment_new (v5, 0.0, 100.0, 1.0, 0, 0);

  spinner_adj11 = (GtkAdjustment *) gtk_adjustment_new (eq1, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj12 = (GtkAdjustment *) gtk_adjustment_new (eq2, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj13 = (GtkAdjustment *) gtk_adjustment_new (eq3, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj14 = (GtkAdjustment *) gtk_adjustment_new (eq4, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj15 = (GtkAdjustment *) gtk_adjustment_new (eq5, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj16 = (GtkAdjustment *) gtk_adjustment_new (eq6, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj17 = (GtkAdjustment *) gtk_adjustment_new (eq7, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj18 = (GtkAdjustment *) gtk_adjustment_new (eq8, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj19 = (GtkAdjustment *) gtk_adjustment_new (eq9, -12.0, 12.0, 1.0, 0, 0);
  spinner_adj10 = (GtkAdjustment *) gtk_adjustment_new (eq0, -12.0, 12.0, 1.0, 0, 0);

  spinner_avd0 = (GtkAdjustment *) gtk_adjustment_new (tv0, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd1 = (GtkAdjustment *) gtk_adjustment_new (tv1, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd2 = (GtkAdjustment *) gtk_adjustment_new (tv2, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd3 = (GtkAdjustment *) gtk_adjustment_new (tv3, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd4 = (GtkAdjustment *) gtk_adjustment_new (tv4, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd5 = (GtkAdjustment *) gtk_adjustment_new (tv5, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd6 = (GtkAdjustment *) gtk_adjustment_new (tv6, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd7 = (GtkAdjustment *) gtk_adjustment_new (tv7, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd8 = (GtkAdjustment *) gtk_adjustment_new (tv8, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd9 = (GtkAdjustment *) gtk_adjustment_new (tv9, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd10 = (GtkAdjustment *) gtk_adjustment_new (tv10, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd11 = (GtkAdjustment *) gtk_adjustment_new (tv11, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd12 = (GtkAdjustment *) gtk_adjustment_new (tv12, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd13 = (GtkAdjustment *) gtk_adjustment_new (tv13, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd14 = (GtkAdjustment *) gtk_adjustment_new (tv14, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd15 = (GtkAdjustment *) gtk_adjustment_new (tv15, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd16 = (GtkAdjustment *) gtk_adjustment_new (tv16, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd17 = (GtkAdjustment *) gtk_adjustment_new (tv17, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd18 = (GtkAdjustment *) gtk_adjustment_new (tv18, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd19 = (GtkAdjustment *) gtk_adjustment_new (tv19, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd20 = (GtkAdjustment *) gtk_adjustment_new (tv20, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd21 = (GtkAdjustment *) gtk_adjustment_new (tv21, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd22 = (GtkAdjustment *) gtk_adjustment_new (tv22, 0.0, 100.0, 1.0, 0, 0);
  spinner_avd23 = (GtkAdjustment *) gtk_adjustment_new (tv23, 0.0, 100.0, 1.0, 0, 0);

  spinner1 = gtk_spin_button_new (spinner_adj1, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner1, 15, 15);
  spinner2 = gtk_spin_button_new (spinner_adj2, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner2, 70, 15);
  spinner3 = gtk_spin_button_new (spinner_adj3, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner3, 125, 15);
  spinner4 = gtk_spin_button_new (spinner_adj4, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner4, 180, 15);
  spinner5 = gtk_spin_button_new (spinner_adj5, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner5, 235, 15);

  spinner11 = gtk_spin_button_new (spinner_adj11, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner11, 15, 50);
  spinner12 = gtk_spin_button_new (spinner_adj12, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner12, 70, 50);
  spinner13 = gtk_spin_button_new (spinner_adj13, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner13, 125, 50);
  spinner14 = gtk_spin_button_new (spinner_adj14, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner14, 180, 50);
  spinner15 = gtk_spin_button_new (spinner_adj15, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner15, 235, 50);
  spinner16 = gtk_spin_button_new (spinner_adj16, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner16, 290, 50);
  spinner17 = gtk_spin_button_new (spinner_adj17, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner17, 345, 50);
  spinner18 = gtk_spin_button_new (spinner_adj18, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner18, 400, 50);
  spinner19 = gtk_spin_button_new (spinner_adj19, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner19, 455, 50);
  spinner10 = gtk_spin_button_new (spinner_adj10, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner10, 510, 50);

  l0 = gtk_label_new("00:00");
  l1 = gtk_label_new("01:00");
  l2 = gtk_label_new("02:00");
  l3 = gtk_label_new("03:00");
  l4 = gtk_label_new("04:00");
  l5 = gtk_label_new("05:00");
  l6 = gtk_label_new("06:00");
  l7 = gtk_label_new("07:00");
  l8 = gtk_label_new("08:00");
  l9 = gtk_label_new("09:00");
  l10 = gtk_label_new("10:00");
  l11 = gtk_label_new("11:00");
  l12 = gtk_label_new("12:00");
  l13 = gtk_label_new("13:00");
  l14 = gtk_label_new("14:00");
  l15 = gtk_label_new("15:00");
  l16 = gtk_label_new("16:00");
  l17 = gtk_label_new("17:00");
  l18 = gtk_label_new("18:00");
  l19 = gtk_label_new("19:00");
  l20 = gtk_label_new("20:00");
  l21 = gtk_label_new("21:00");
  l22 = gtk_label_new("22:00");
  l23 = gtk_label_new("23:00");

  gtk_fixed_put(GTK_FIXED(fixed), l0, 15, 100 );
  gtk_fixed_put(GTK_FIXED(fixed), l1, 15, 130 );
  gtk_fixed_put(GTK_FIXED(fixed), l2, 15, 160 );
  gtk_fixed_put(GTK_FIXED(fixed), l3, 15, 190 );
  gtk_fixed_put(GTK_FIXED(fixed), l4, 115, 100 );
  gtk_fixed_put(GTK_FIXED(fixed), l5, 115, 130 );
  gtk_fixed_put(GTK_FIXED(fixed), l6, 115, 160 );
  gtk_fixed_put(GTK_FIXED(fixed), l7, 115, 190 );
  gtk_fixed_put(GTK_FIXED(fixed), l8, 215, 100 );
  gtk_fixed_put(GTK_FIXED(fixed), l9, 215, 130 );
  gtk_fixed_put(GTK_FIXED(fixed), l10, 215, 160 );
  gtk_fixed_put(GTK_FIXED(fixed), l11, 215, 190 );
  gtk_fixed_put(GTK_FIXED(fixed), l12, 315, 100 );
  gtk_fixed_put(GTK_FIXED(fixed), l13, 315, 130 );
  gtk_fixed_put(GTK_FIXED(fixed), l14, 315, 160 );
  gtk_fixed_put(GTK_FIXED(fixed), l15, 315, 190 );
  gtk_fixed_put(GTK_FIXED(fixed), l16, 415, 100 );
  gtk_fixed_put(GTK_FIXED(fixed), l17, 415, 130 );
  gtk_fixed_put(GTK_FIXED(fixed), l18, 415, 160 );
  gtk_fixed_put(GTK_FIXED(fixed), l19, 415, 190 );
  gtk_fixed_put(GTK_FIXED(fixed), l20, 515, 100 );
  gtk_fixed_put(GTK_FIXED(fixed), l21, 515, 130 );
  gtk_fixed_put(GTK_FIXED(fixed), l22, 515, 160 );
  gtk_fixed_put(GTK_FIXED(fixed), l23, 515, 190 );

  gtk_widget_set_size_request(l0, 40, 25);
  gtk_widget_set_size_request(l1, 40, 25);
  gtk_widget_set_size_request(l2, 40, 25);
  gtk_widget_set_size_request(l3, 40, 25);
  gtk_widget_set_size_request(l4, 40, 25);
  gtk_widget_set_size_request(l5, 40, 25);
  gtk_widget_set_size_request(l6, 40, 25);
  gtk_widget_set_size_request(l7, 40, 25);
  gtk_widget_set_size_request(l8, 40, 25);
  gtk_widget_set_size_request(l9, 40, 25);
  gtk_widget_set_size_request(l10, 40, 25);
  gtk_widget_set_size_request(l11, 40, 25);
  gtk_widget_set_size_request(l12, 40, 25);
  gtk_widget_set_size_request(l13, 40, 25);
  gtk_widget_set_size_request(l14, 40, 25);
  gtk_widget_set_size_request(l15, 40, 25);
  gtk_widget_set_size_request(l16, 40, 25);
  gtk_widget_set_size_request(l17, 40, 25);
  gtk_widget_set_size_request(l18, 40, 25);
  gtk_widget_set_size_request(l19, 40, 25);
  gtk_widget_set_size_request(l20, 40, 25);
  gtk_widget_set_size_request(l21, 40, 25);
  gtk_widget_set_size_request(l22, 40, 25);
  gtk_widget_set_size_request(l23, 40, 25);

  spinner_vd0 = gtk_spin_button_new (spinner_avd0, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd0, 60, 100);
  spinner_vd1 = gtk_spin_button_new (spinner_avd1, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd1, 60, 130);
  spinner_vd2 = gtk_spin_button_new (spinner_avd2, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd2, 60, 160);
  spinner_vd3 = gtk_spin_button_new (spinner_avd3, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd3, 60, 190);
  spinner_vd4 = gtk_spin_button_new (spinner_avd4, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd4, 160, 100);
  spinner_vd5 = gtk_spin_button_new (spinner_avd5, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd5, 160, 130);
  spinner_vd6 = gtk_spin_button_new (spinner_avd6, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd6, 160, 160);
  spinner_vd7 = gtk_spin_button_new (spinner_avd7, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd7, 160, 190);
  spinner_vd8 = gtk_spin_button_new (spinner_avd8, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd8, 260, 100);
  spinner_vd9 = gtk_spin_button_new (spinner_avd9, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd9, 260, 130);
  spinner_vd10 = gtk_spin_button_new (spinner_avd10, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd10, 260, 160);
  spinner_vd11 = gtk_spin_button_new (spinner_avd11, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd11, 260, 190);
  spinner_vd12 = gtk_spin_button_new (spinner_avd12, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd12, 360, 100);
  spinner_vd13 = gtk_spin_button_new (spinner_avd13, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd13, 360, 130);
  spinner_vd14 = gtk_spin_button_new (spinner_avd14, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd14, 360, 160);
  spinner_vd15 = gtk_spin_button_new (spinner_avd15, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd15, 360, 190);
  spinner_vd16 = gtk_spin_button_new (spinner_avd16, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd16, 460, 100);
  spinner_vd17 = gtk_spin_button_new (spinner_avd17, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd17, 460, 130);
  spinner_vd18 = gtk_spin_button_new (spinner_avd18, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd18, 460, 160);
  spinner_vd19 = gtk_spin_button_new (spinner_avd19, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd19, 460, 190);
  spinner_vd20 = gtk_spin_button_new (spinner_avd20, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd20, 560, 100);
  spinner_vd21 = gtk_spin_button_new (spinner_avd21, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd21, 560, 130);
  spinner_vd22 = gtk_spin_button_new (spinner_avd22, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd22, 560, 160);
  spinner_vd23 = gtk_spin_button_new (spinner_avd23, 1.0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), spinner_vd23, 560, 190);

  g_signal_connect (spinner1, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedV1), 
                    NULL);
  g_signal_connect (spinner2, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedV2), 
                    NULL);
  g_signal_connect (spinner3, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedV3), 
                    NULL);
  g_signal_connect (spinner4, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedV4), 
                    NULL);
  g_signal_connect (spinner5, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedV5), 
                    NULL);

  g_signal_connect (spinner11, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked1), 
                    NULL);
  g_signal_connect (spinner12, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked2), 
                    NULL);
  g_signal_connect (spinner13, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked3), 
                    NULL);
  g_signal_connect (spinner14, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked4), 
                    NULL);
  g_signal_connect (spinner15, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked5), 
                    NULL);
  g_signal_connect (spinner16, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked6), 
                    NULL);
  g_signal_connect (spinner17, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked7), 
                    NULL);
  g_signal_connect (spinner18, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked8), 
                    NULL);
  g_signal_connect (spinner19, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked9), 
                    NULL);
  g_signal_connect (spinner10, 
                    "value-changed", 
                    G_CALLBACK (spin_clicked0), 
                    NULL);
  //--------------------------------------------

  g_signal_connect (spinner_vd0, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv0), 
                    NULL);
  g_signal_connect (spinner_vd1, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv1), 
                    NULL);
  g_signal_connect (spinner_vd2, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv2), 
                    NULL);
  g_signal_connect (spinner_vd3, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv3), 
                    NULL);
  g_signal_connect (spinner_vd4, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv4), 
                    NULL);
  g_signal_connect (spinner_vd5, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv5), 
                    NULL);
  g_signal_connect (spinner_vd6, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv6), 
                    NULL);
  g_signal_connect (spinner_vd7, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv7), 
                    NULL);
  g_signal_connect (spinner_vd8, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv8), 
                    NULL);
  g_signal_connect (spinner_vd9, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv9), 
                    NULL);
  g_signal_connect (spinner_vd10, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv10), 
                    NULL);
  g_signal_connect (spinner_vd11, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv11), 
                    NULL);
  g_signal_connect (spinner_vd12, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv12), 
                    NULL);
  g_signal_connect (spinner_vd13, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv13), 
                    NULL);
  g_signal_connect (spinner_vd14, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv14), 
                    NULL);
  g_signal_connect (spinner_vd15, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv15), 
                    NULL);
  g_signal_connect (spinner_vd16, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv16), 
                    NULL);
  g_signal_connect (spinner_vd17, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv17), 
                    NULL);
  g_signal_connect (spinner_vd18, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv18), 
                    NULL);
  g_signal_connect (spinner_vd19, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv19), 
                    NULL);
  g_signal_connect (spinner_vd20, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv20), 
                    NULL);
  g_signal_connect (spinner_vd21, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv21), 
                    NULL);
  g_signal_connect (spinner_vd22, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv22), 
                    NULL);
  g_signal_connect (spinner_vd23, 
                    "value-changed", 
                    G_CALLBACK (spin_clickedTv23), 
                    NULL);
  //--------------------------------------------

  gtk_signal_connect (GTK_OBJECT (button2), "clicked",
		      GTK_SIGNAL_FUNC (destroy), NULL);  

  gtk_signal_connect (GTK_OBJECT (button1), "clicked",
		      GTK_SIGNAL_FUNC (Dialog), NULL);  

  g_signal_connect_swapped(G_OBJECT(window), "destroy", 
			   G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
