void inf ();
void editar();
void añadir();
void eliminar();
int menu ();
void noValido ();
char* salir (char resp[10]);
int numObjAñadir (int indexFinal);
int añadirTipo ();
int añadirMaterial ();
char* añadirNombre(int tipo, int material, int index, char nombres[][2][11][20]);
float añadirDatos (int a,int index, char nombres[][2][11][20], int tipo, int material);
void tablaEditar (int tipo, int material, int index, char nombres[][2][11][20], float datos[][2][10][2]);
int opcEditar();
char* nombreAEditar (int tipo, int material,char nombres[][2][11][20],char buscar[20]);
int obtenerTipo();
int obtenerMaterial();
int buscarIndex(int tipo, int material, char buscar[],char nombres[][2][11][20]);
char* editarNombre (int tipo, int material, int index, char nombres[][2][11][20],float datos [][2][10][2]);
float editarCantidad ();
float editarPrecio ();
int comprobarReplicas (int tipo, int material, char nombres[][2][11][20],int index);
float validarNum (int insp);
char* nombreAEliminar (int tipo, int material, char buscar [],char nombres[][2][11][20],char vacio[]);
char* vaciarStr (char str[][2][11][20]);
char* reordenarNombre (int tipo, int material, int i,char nombres[][2][11][20]);
void imprimirTabla(char nombres [][2][11][20], char vacio[], float datos [][2][10][2]);
float reordenarDatos(int tipo, int material, int i,float datos[][2][10][2],int j);
int comprobarVacio (int tipo, int material, char nombres[][2][11][20],char vacio[]);