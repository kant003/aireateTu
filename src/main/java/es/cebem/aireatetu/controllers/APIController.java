package es.cebem.aireatetu.controllers;

import java.util.Date;
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
    Date date = new Date();
    datosModel.setTemperature(Float.parseFloat(temp));
    datosModel.setCo2(Float.parseFloat(co2));
    datosModel.setHumidity(Float.parseFloat(humd));
    datosModel.setDate(new Date());

    datosService.addDatos(datosModel);
    return temp + ", " + humd + ", " + co2 + ", " + date + ": SUCCESS!";
  }

}
