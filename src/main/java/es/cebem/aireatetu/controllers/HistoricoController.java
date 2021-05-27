package es.cebem.aireatetu.controllers;

import java.util.ArrayList;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import es.cebem.aireatetu.models.DatosModel;
import es.cebem.aireatetu.services.DatosService;

@Controller
public class HistoricoController {

  @Autowired
  DatosService datosService;

  @RequestMapping("/historico")
  public String datosHistory(Model model) {
    ArrayList<DatosModel> datos = datosService.getDatos();
    model.addAttribute("datos", datos);
    return "historico";
  }

}
