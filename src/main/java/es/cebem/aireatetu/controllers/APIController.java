package es.cebem.aireatetu.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import es.cebem.aireatetu.models.DatosModel;
import es.cebem.aireatetu.services.DatosService;

@RestController
public class APIController {

  @Autowired
  DatosService datosService;

  @GetMapping("/api/insertarDatos")
  public String insertarDatos(@RequestParam String temp, @RequestParam String humd,
      @RequestParam String co2) {
    DatosModel datosModel = new DatosModel();
    datosModel.setTemperature(Float.parseFloat(temp));
    datosModel.setCo2(Float.parseFloat(co2));
    datosModel.setHumidity(Float.parseFloat(humd));

    datosService.addDatos(datosModel);
    return temp + ", " + humd + ", " + co2 + ": SUCCESS!";
  }

}
