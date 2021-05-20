package es.cebem.aireatetu.controllers;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class APIController {
  
  // TODO: Añadir datos Service!

  @GetMapping("/api/insertarDatos")
  public String insertarDatos(@RequestParam String temp, @RequestParam String humd, @RequestParam String co2) {
    return temp + ", " + humd + ", " + co2;
  }

}
