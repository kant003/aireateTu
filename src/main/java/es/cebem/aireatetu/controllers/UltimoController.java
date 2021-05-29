package es.cebem.aireatetu.controllers;

import java.util.ArrayList;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import es.cebem.aireatetu.models.DatosModel;
import es.cebem.aireatetu.services.DatosService;

@Controller
public class UltimoController {

  @Autowired
  DatosService datosService;

  @RequestMapping("/ultimodato")
  public String UltimoDato(Model model) {
    ArrayList<DatosModel> datos = datosService.getDatos();
    if (datos != null && !datos.isEmpty()) {
        ultimo = datos.get(datos.size()-1);
      }
    return ultimo;
  }

}
