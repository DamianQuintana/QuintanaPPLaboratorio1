struct
{
    int dia;
    int mes;
    int anio;

} typedef eFecha; //Definición de la estructura de fecha
struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    float edad;

} typedef eMascota; //Definicion de la estructura de mascota
struct
{
    int id;
    char nombreColor[20];

} typedef eColor; //Definicion de la estructura de color
struct
{
    int id;
    char descripcion[20];

} typedef eTipo; // Definición de la estructura de tipo

struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha; //Estructura anidada de fecha
} typedef eTrabajo; //Definicion de la estructura de trabajo

/** \brief Inicializamos el array de mascotas, ponemos la edad en -1 para indicar libre
 *
 * \param mascota eMascota* Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \return int Devolvemos un 0 para indicar OK
 *
 */
int inicializarMascotas(eMascota* mascota, int tam);
/** \brief Buscamos la primer posicion libre en el array de mascotas
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param size int Tamaño del array
 * \return int Devolvemos la posicion libre del array
 *
 */
int buscarMascotaLibre(eMascota* mascota, int size);
/** \brief Buscamos la primer posicion libre del array y cargamos los datos en el
 *
 * \param mascota eMascota*Puntero al array de mascota
 * \param tam intTamaño del array
 * \param tipo eTipo*Puntero al array de tipo
 * \param tam2 intTamaño del array tipo
 * \param color eColor*Puntero al array de color
 * \param tam3 intTamaño del array de color
 * \param id int
 * \param i int
 * \return int
 *
 */
int agregarMascota(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, int id, int i);
/** \brief Imprime las posiciones edl array que no tengan su edad en -1
 *
 * \param mascota eMascota* Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \param tipo eTipo*Puntero al array de tipo
 * \param tam2 intTamaño del array de tipo
 * \param color eColor*Puntero al array de color
 * \param tam3 intTamaño del array de color
 * \return int Devolvemos 0 para indicar OK
 *
 */
int imprimirMascotas(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3);
/** \brief Busca una mascota por ID y nos devuelve su posicion del array
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \param id int ID a buscar
 * \return int Posicion del array
 *
 */
int buscarMascotaPorID(eMascota* mascota, int tam, int id);
/** \brief
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \param id int ID a buscar
 * \return int 0 si esta todo OK
 *
 */
int imprimirUnaMascota(eMascota* mascota, int tam, int id);
/** \brief
 *
 * \param mascota eMascota* Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \param id intID a buscar
 * \param tipo eTipo*Puntero al array de tipo
 * \param tam2 intTamaño del array tipo
 * \param color eColor*Puntero al array de color
 * \param size3 intTamaño del array color
 * \return int 0 si todo ok
 *
 */
int ModificarMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int size3);
/** \brief Toma el valor de id de mascota y si se decide dar de baja pone su edad en -1
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param tam intTamaño del array
 * \param id int ID a dar de baja
 * \return int Devuelve 0 si se dio de baja -1 si no se dio de baja
 *
 */
int quitarMascota(eMascota* mascota, int tam, int id);
/** \brief Ordena el array de mascotas
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param size intTamaño del array
 * \return int 0 si esta todo OK
 *
 */
int ordenarMascotas(eMascota* mascota, int size);
