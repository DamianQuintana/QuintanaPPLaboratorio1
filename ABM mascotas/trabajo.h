
/** \brief Inicializa el array de trabajos, pone su id de servicio en -1
 *
 * \param trabajo eTrabajo* Puntero al array de trabajos
 * \param tam int Tama�o del array de trabajo
 * \return int Devuelve 0 si todo OK
 *
 */
int inicializarTrabajos(eTrabajo* trabajo, int tam);
/** \brief Busca la primer posicion del array de trabajo libre
 *
 * \param trabajo eTrabajo*Puntero al array de trabajos
 * \param size int Tama�o del array de trabajo
 * \return int Devuelve la primer posicion libre del array
 *
 */
int buscarTrabajoLibre(eTrabajo* trabajo, int size);
/** \brief Agrega los datos ingresado por teclado en el primer lugar libre del array
 *
 * \param trabajo eTrabajo*Puntero al array de trabajos
 * \param size intTama�o del array de trabajo
 * \param i int posicion del array
 * \param id int id autoincremental
 * \param mascota eMascota*Puntero al array de mascotas
 * \param size2 intTama�o del array de mascotas
 * \param servicio eServicio*Puntero al array de servicios
 * \param size3 intTama�o del array de servicios
 * \return int devuelve 0 si todo ok
 *
 */
int agregarTrabajo(eTrabajo* trabajo, int size, int i, int id, eMascota* mascota, int size2, eServicio* servicio, int size3);
/** \brief Imprime los trabajos que esten dados de alta
 *
 * \param trabajo eTrabajo*Puntero al array de trabajos
 * \param size intTama�o del array de trabajo
 * \param servicio eServicio*Puntero al array de servicios
 * \param size2 intTama�o del array de servicios
 * \return intDevuelve 0 si todo OK
 *
 */
int imprimirTrabajos(eTrabajo* trabajo, int size, eServicio* servicio, int size2);
