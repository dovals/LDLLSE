#include "LDL.h"

class SocioClub{

    private:
        int numeroSocio;
        std::string NombreSocio;
        std::string Domicilio;
        int AnioIngreso;


    public:
        SocioClub() {}
        SocioClub(int numeroSocio, std::string NombreSocio, std::string Domicilio, int AnioIngreso)
        : numeroSocio(numeroSocio), NombreSocio(NombreSocio), Domicilio(Domicilio),  AnioIngreso(AnioIngreso) {}

        friend std::ostream& operator<<(std::ostream& os, const SocioClub& socio){
            os << "Numero de socio: " << socio.numeroSocio << std::endl;
            os << "Nombre: " << socio.NombreSocio << std::endl;
            os << "Domicilio: " << socio.Domicilio << std::endl;
            os << "Anio de ingreso: " << socio.AnioIngreso << std::endl;
            return os;
        }

    void AgregarUsuario(int numeroSocio, std::string NombreSocio, std::string Domicilio, int AnioIngreso, LDLLSE<SocioClub>& lista){
        SocioClub nuevoSocio(numeroSocio, NombreSocio, Domicilio, AnioIngreso);
        nodo<SocioClub>* aux = lista.primero();
        while (aux != nullptr) {
            if (aux->data.numeroSocio == numeroSocio) {
                std::cout << "El numero de socio ya existe." << std::endl;
                return;
            }
            aux = aux->sig;
        }
        if(lista.vacia()){
            lista.inserta(nullptr, nuevoSocio);
        }
        else{
            lista.inserta(lista.ultimo(), nuevoSocio);
        }
    }


    void BuscarSocio(std::string nombre, std::string domicilio,LDLLSE<SocioClub>& lista){
        nodo<SocioClub>* aux = lista.primero();
        while(aux != nullptr) {
            if (aux->data.NombreSocio == nombre && aux->data.Domicilio == domicilio) {
                system("cls");
                std::cout << "Socio encontrado: " << std::endl;
                std::cout << aux->data << std::endl;
                return;
            }
            aux = aux->sig;
        }
        std::cout << "Socio no encontrado." << std::endl;
    }

    void DarBajaUsuario(int numeroSocio, LDLLSE<SocioClub>& lista){
        nodo<SocioClub>* aux = lista.primero();
        while(aux != nullptr){
            if(aux->data.numeroSocio == numeroSocio){
                std::cout << "Dando de baja al socio: " << std::endl;
                std::cout << aux->data << std::endl;
                lista.elimina(aux);
                return;
            }
            aux = aux->sig;
        }
        std::cout << "Socio no encontrado." << std::endl;
    }


    int TotalDeSocios(LDLLSE<SocioClub>& lista){
        nodo<SocioClub>* aux = lista.primero();
        int cont = 0;
        while(aux!=nullptr){
            cont++;
            aux=aux->sig;
        }
        return cont;
    }

    void ordenar(LDLLSE<SocioClub>& lista) {
    if (lista.vacia() || lista.primero()->sig == nullptr) {
        return;
    }
    nodo<SocioClub>* nodoI = lista.primero();
    while (nodoI != nullptr) {
        nodo<SocioClub>* nodoJ = nodoI->sig;
        while (nodoJ != nullptr) {
            if (nodoI->data.numeroSocio > nodoJ->data.numeroSocio) {
                SocioClub temp = nodoI->data;
                nodoI->data = nodoJ->data;
                nodoJ->data = temp;
            }
            nodoJ = nodoJ->sig;
        }
        nodoI = nodoI->sig;
        }
    }


    void GenerarReporte(LDLLSE<SocioClub>&lista){
        nodo<SocioClub>* aux = lista.primero();
        while(aux!=nullptr){
            std::cout<<"Numero del Socio: "<<aux->data.numeroSocio<<"\nNombre: "<<aux->data.NombreSocio<<"\nDomicilio: "<<aux->data.Domicilio<<"\nAnio de Ingreso: "<<aux->data.AnioIngreso<<"\n----------------------------\n";
            aux=aux->sig;
        }
    }
};//termina clase SocioClub


int main(){
    LDLLSE<SocioClub> listaSocios;
    SocioClub socio;
    int opc = 0,numeroSocio,AnioIngreso;
    std::string NombreSocio, Domicilio;
    while(true)
    {
        std::cout<<"\nElija una de las siguientes opciones:\n"
        "1.-Registrar nuevo Socio\n2.-Dar de Baja Usuario\n3.-Generar Reporte\n4.-Buscar Socio\n5.-Total de Socios\n6.-Salir"<<std::endl;
        std::cin>>opc;
        switch(opc)
        {
            case 1:
                system("cls");
                std::cout<<"Numero Socio"<<std::endl;
                std::cin>>numeroSocio;
                std::cout<<"Nombre Socio"<<std::endl;
                std::cin>>NombreSocio;
                std::cout<<"Domicilio Socio"<<std::endl;
                std::cin>>Domicilio;
                std::cout<<"Anio de Registro"<<std::endl;
                std::cin>>AnioIngreso;
                socio.AgregarUsuario(numeroSocio,NombreSocio,Domicilio,AnioIngreso,listaSocios);

            break;

            case 2:
                system("cls");
                std::cout<<"Numero de socio a dar de baja"<<std::endl;
                std::cin>>numeroSocio;
                socio.DarBajaUsuario(numeroSocio, listaSocios);
            break;

            case 3:
                system("cls");
                socio.ordenar(listaSocios);
                socio.GenerarReporte(listaSocios);
            break;

            case 4:
                system("cls");
                std::cout<<"ingrese los datos del socio a buscar\nNombre"<<std::endl;
                std::cin>>NombreSocio;
                std::cout<<"Domicilio"<<std::endl;
                std::cin>>Domicilio;
                socio.BuscarSocio(NombreSocio,Domicilio,listaSocios);
            break;

            case 5:
                system("cls");
                std::cout<<"Total de socios: "<<socio.TotalDeSocios(listaSocios)<<std::endl;
            break;

            case 6:
                exit(0);
            break;

            default:
                system("cls");
                std::cout<<"Opcion incorrecta o inexistente"<<std::endl;
            break;
        }
    }
    return 0;
}

