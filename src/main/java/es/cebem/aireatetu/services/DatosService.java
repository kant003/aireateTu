package es.cebem.aireatetu.services;

import java.util.ArrayList;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import es.cebem.aireatetu.models.DatosModel;
import es.cebem.aireatetu.repositories.DatosRepository;

@Service
public class DatosService {

  @Autowired
  DatosRepository datosRepository;

  public DatosModel addDatos(DatosModel datosModel) {
    return datosRepository.save(datosModel);
  }

  public ArrayList<DatosModel> getDatos() {
    return (ArrayList<DatosModel>) datosRepository.findAll();
  }

}
