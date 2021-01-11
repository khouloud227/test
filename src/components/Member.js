import React, { useState } from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import { Button, ButtonGroup } from 'react-bootstrap';
import { tableau } from './Data'

function Main() {
    const [frommember, setfrommember] = useState(tableau);
    const [indice, setindice] = useState(0);
    const [nomcomplet, setnomcomplet] = useState();
    const [all, setall] = useState([]);
    const [filtred, setfiltred] = useState([]);
    const [begin, setbegin] = useState(false);


    const next = (status) => {

        if (indice == 10) {
            setfiltred((old) => [{ name: nomcomplet, status }, ...old])
            setnomcomplet(frommember[indice - 1].prenom + " " + frommember[indice - 1].nom);
            setall((old) => [{ name: nomcomplet, status }, ...old])
            document.getElementById('presence').innerHTML = ""
        } else {
            if (status == "go") {
                setindice(indice + 1);
                setnomcomplet(frommember[indice].prenom + " " + frommember[indice].nom);

            } else {
                setfiltred((old) => [{ name: nomcomplet, status }, ...old])
                setindice(indice + 1);
                setnomcomplet(frommember[indice].prenom + " " + frommember[indice].nom);
                setall((old) => [{ name: nomcomplet, status }, ...old])

            }
        }
    }

    const filtre = (status) => {
        if (status == "Tous") {
            setfiltred(all)
        } else {

            const res = all.filter(element => element.status == status);

            setfiltred(res);
        }
    }
    return (
        <div>
            <div>
            <div id="presence">
                    <div>
                        {begin ? null : <Button onClick={() => {
                            setbegin(!begin);
                            setnomcomplet(frommember[indice].prenom + " " + frommember[indice].nom);
                            next("go");
                        }} >Commencer</Button>}
                        <h4 style={{color:'white', margintop:'20px'}}> {nomcomplet}  </h4>
                    </div>
                    <div id="buttons"  >
                        <Button onClick={() => next("Present")} variant="success">Present</Button>
                        <Button onClick={() => next("Excusé")} variant="warning">Excusé</Button>
                        <Button onClick={() => next("Abscent")} variant="danger">Abscent</Button>
                    </div>
                </div>
                <div>
                    <div >
                        <ButtonGroup id='buttons' size="sm" >
                            <Button onClick={() => filtre("Tous")}>Tous</Button>
                            <Button onClick={() => filtre("Abscent")}>Abscent</Button>
                            <Button onClick={() => filtre("Present")} >Present</Button>
                        </ButtonGroup>

                    </div>
                </div>
                <div>
                    <ul>
                        {filtred && filtred.map((element, indice) =>
                            <div key={indice} className="card card-body mb-1">
                                <div>
                                    <div >
                                        <h6 style={{ marginBottom: 0 }}>
                                            {element.name}
                                        </h6>
                                    </div>
                                    <div style={{ float: 'right' }}>
                                        <Button variant="secondary">
                                            {element.status}
                                        </Button>
                                    </div>
                                </div>
                            </div>
                        )}
                    </ul>
                </div>
            </div>
        </div>
    )
}

export default Main
  