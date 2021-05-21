package es.cebem.aireatetu.repositories;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;
import es.cebem.aireatetu.models.DatosModel;

@Repository
public interface DatosRepository extends CrudRepository<DatosModel, Integer> {

}
