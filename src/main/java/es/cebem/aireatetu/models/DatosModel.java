package es.cebem.aireatetu.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "Datos")
public class DatosModel {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private int ID;
  private float temperature;
  private float co2;
  private float humidity;

  public int getID() {
    return ID;
  }

  public float getTemperature() {
    return temperature;
  }

  public void setTemperature(float temperature) {
    this.temperature = temperature;
  }

  public float getCo2() {
    return co2;
  }

  public void setCo2(float co2) {
    this.co2 = co2;
  }

  public float getHumidity() {
    return humidity;
  }

  public void setHumidity(float humidity) {
    this.humidity = humidity;
  }

  @Override
  public String toString() {
    return "DatosModel [ID=" + ID + ", co2=" + co2 + ", humidity=" + humidity + ", temperature="
        + temperature + "]";
  }

}
